#include "FallDetection.h"
#include "Textures.h"

CFallDetection::CFallDetection(float x, float y) : CGameObject(x, y)
{
	this->ay = GRAVITY;
}

void CFallDetection::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CFallDetection::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->obj->IsBlocking()) return;

	if (e->ny < 0 && e->obj->IsBlocking())
	{
		vy = 0;
	}
}

void CFallDetection::Render()
{
	//RenderBoundingBox();
}

void CFallDetection::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CFallDetection::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - FALL_CELL_WIDTH / 2;
	t = y - FALL_CELL_HEIGHT / 2;
	r = l + FALL_CELL_WIDTH;
	b = t + FALL_CELL_HEIGHT;
}


