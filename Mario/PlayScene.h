#pragma once
#include "HanabiScene.h"
#include "HanabiSprite.h"
#include "HanabiMap.h"
#include "HanabiShape.h"
#include "HanabiWorld.h"
#include "WorldListener.h"
#include "Player.h"
#include "Platform.h"
#include "Goomba.h"
#include "WingGoomba.h"
#include "Koopa.h"
#include "QuestionBrick.h"
#include "Coin.h"
#include "CoinBrick.h"

class PlayScene: public Scene
{
private:

	//Camera
	Camera cam;
	//load map
	TMXLoader mapLoader;
	TMXMap* map;
	
	//World
	World world;

	//listen to collision between bodies
	WorldListener worldListener;

	//player
	Player player;

	//draw texture, sprite, ...
	SpriteBatch* batch;

	//enemies
	Texture enemiesTexture;
	Texture objectsTexture;
	std::vector<Goomba*> goombas;
	std::vector<WingGoomba*> wingGoombas;
	std::vector<Koopa*> koopas;

	//objects
	std::vector<QuestionBrick*> questionBricks;
	std::vector<Coin*> coins;
	std::vector<CoinBrick*> coinBricks;

public:
	PlayScene();
	~PlayScene();

	void SetBatch(SpriteBatch* batch);
	void HandlePhysics(float dt);
	void Render();

	void Create() override;
	void Update(float dt) override;
	void Release() override;
	bool isOver();
};

