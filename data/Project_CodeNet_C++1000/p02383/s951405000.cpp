#include <iostream>
#include <string>

using namespace std;

class Dice
{
public:
	enum DICE_FACE
	{
		eTop,
		eFront,
		eRight,
		eLeft,
		eBack,
		eBottom
	};

	Dice(int t, int f, int r, int l, int ba, int bo)
	{
		this->mTopValue = t;
		this->mFrontValue = f;
		this->mRightValue = r;
		this->mLeftValue = l;
		this->mBackValue = ba;
		this->mBottomValue = bo;
		this->meDiceTop = eTop;
		this->meFront = eFront;
	}

	virtual ~Dice(){}

	int GetTop()
	{
		int		R;

		switch (this->meDiceTop)
		{
		case Dice::eTop:
			R = this->mTopValue;
			break;
		case Dice::eFront:
			R = this->mFrontValue;
			break;
		case Dice::eRight:
			R = this->mRightValue;
			break;
		case Dice::eLeft:
			R = this->mLeftValue;
			break;
		case Dice::eBack:
			R = this->mBackValue;
			break;
		case Dice::eBottom:
			R = this->mBottomValue;
			break;
		default:
			break;
		}

		return (R);
	}

	void ComE()
	{
		DICE_FACE		SWNE[5];

		switch (this->meDiceTop)
		{
		case Dice::eTop:
			SWNE[0] = DICE_FACE::eFront;
			SWNE[1] = DICE_FACE::eLeft;
			SWNE[2] = DICE_FACE::eBack;
			SWNE[3] = DICE_FACE::eRight;
			SWNE[4] = DICE_FACE::eFront;
			break;
		case Dice::eFront:
			SWNE[0] = DICE_FACE::eBottom;
			SWNE[1] = DICE_FACE::eLeft;
			SWNE[2] = DICE_FACE::eTop;
			SWNE[3] = DICE_FACE::eRight;
			SWNE[4] = DICE_FACE::eBottom;
			break;
		case Dice::eRight:
			SWNE[0] = DICE_FACE::eBottom;
			SWNE[1] = DICE_FACE::eFront;
			SWNE[2] = DICE_FACE::eTop;
			SWNE[3] = DICE_FACE::eBack;
			SWNE[4] = DICE_FACE::eBottom;
			break;
		case Dice::eLeft:
			SWNE[0] = DICE_FACE::eBottom;
			SWNE[1] = DICE_FACE::eBack;
			SWNE[2] = DICE_FACE::eTop;
			SWNE[3] = DICE_FACE::eFront;
			SWNE[4] = DICE_FACE::eBottom;
			break;
		case Dice::eBack:
			SWNE[0] = DICE_FACE::eBottom;
			SWNE[1] = DICE_FACE::eRight;
			SWNE[2] = DICE_FACE::eTop;
			SWNE[3] = DICE_FACE::eLeft;
			SWNE[4] = DICE_FACE::eBottom;
			break;
		case Dice::eBottom:
			SWNE[0] = DICE_FACE::eFront;
			SWNE[1] = DICE_FACE::eRight;
			SWNE[2] = DICE_FACE::eBack;
			SWNE[3] = DICE_FACE::eLeft;
			SWNE[4] = DICE_FACE::eFront;
			break;
		default:
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			if (this->meFront == SWNE[i])
			{
				this->meDiceTop = SWNE[i + 1];
				break;
			}
		}
	}

	void ComW()
	{
		DICE_FACE		SENW[5];

		switch (this->meDiceTop)
		{
		case Dice::eTop:
			SENW[0] = DICE_FACE::eFront;
			SENW[1] = DICE_FACE::eRight;
			SENW[2] = DICE_FACE::eBack;
			SENW[3] = DICE_FACE::eLeft;
			SENW[4] = DICE_FACE::eFront;
			break;
		case Dice::eFront:
			SENW[0] = DICE_FACE::eBottom;
			SENW[1] = DICE_FACE::eRight;
			SENW[2] = DICE_FACE::eTop;
			SENW[3] = DICE_FACE::eLeft;
			SENW[4] = DICE_FACE::eBottom;
			break;
		case Dice::eRight:
			SENW[0] = DICE_FACE::eBottom;
			SENW[1] = DICE_FACE::eBack;
			SENW[2] = DICE_FACE::eTop;
			SENW[3] = DICE_FACE::eFront;
			SENW[4] = DICE_FACE::eBottom;
			break;
		case Dice::eLeft:
			SENW[0] = DICE_FACE::eBottom;
			SENW[1] = DICE_FACE::eFront;
			SENW[2] = DICE_FACE::eTop;
			SENW[3] = DICE_FACE::eBack;
			SENW[4] = DICE_FACE::eBottom;
			break;
		case Dice::eBack:
			SENW[0] = DICE_FACE::eBottom;
			SENW[1] = DICE_FACE::eLeft;
			SENW[2] = DICE_FACE::eTop;
			SENW[3] = DICE_FACE::eRight;
			SENW[4] = DICE_FACE::eBottom;
			break;
		case Dice::eBottom:
			SENW[0] = DICE_FACE::eFront;
			SENW[1] = DICE_FACE::eLeft;
			SENW[2] = DICE_FACE::eBack;
			SENW[3] = DICE_FACE::eRight;
			SENW[4] = DICE_FACE::eFront;
			break;
		default:
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			if (this->meFront == SENW[i])
			{
				this->meDiceTop = SENW[i + 1];
				break;
			}
		}
	}

	DICE_FACE	Reverse(DICE_FACE dice)
	{
		DICE_FACE		R;

		switch (dice)
		{
		case Dice::eTop:
			R = Dice::eBottom;
			break;
		case Dice::eFront:
			R = Dice::eBack;
			break;
		case Dice::eRight:
			R = Dice::eLeft;
			break;
		case Dice::eLeft:
			R = Dice::eRight;
			break;
		case Dice::eBack:
			R = Dice::eFront;
			break;
		case Dice::eBottom:
			R = Dice::eTop;
			break;
		default:
			break;
		}

		return (R);
	}

	void ComS()
	{
		DICE_FACE		dice = this->meFront;

		this->meFront = this->meDiceTop;
		this->meDiceTop = this->Reverse(dice);
	}

	void ComN()
	{
		DICE_FACE		dice = this->meDiceTop;

		this->meDiceTop = this->meFront;
		this->meFront = this->Reverse(dice);
	}

private:
	int			mTopValue;
	int			mFrontValue;
	int			mRightValue;
	int			mLeftValue;
	int			mBackValue;
	int			mBottomValue;
	DICE_FACE	meDiceTop;
	DICE_FACE	meFront;
};

int main()
{
	int t, f, r, l, ba, bo;

	cin >> t >> f >> r >> l >> ba >> bo;
	cin.ignore();
	Dice	dice(t, f, r, l, ba, bo);

	string		str;
	getline(cin, str);

	for (auto it : str)
	{
		switch (it)
		{
		case 'E':
		case 'e':
			dice.ComE();
			break;
		case 'N':
		case 'n':
			dice.ComN();
			break;
		case 'S':
		case 's':
			dice.ComS();
			break;
		case 'W':
		case 'w':
			dice.ComW();
			break;
		default:
			break;
		}
	}

	cout << dice.GetTop() << "\n";

	return 0;
}