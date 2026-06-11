#include "iostream"
#include "string"

int Dice[6];

class DiceMove
{
private:
public:
	DiceMove(){}
	void Move(char dir) {
		int temp;
		if (dir == 'N') {
			temp = Dice[0];
			Dice[0] = Dice[1];
			Dice[1] = Dice[5];
			Dice[5] = Dice[4];
			Dice[4] = temp;
		}
		if (dir == 'S') {
			temp = Dice[0];
			Dice[0] = Dice[4];
			Dice[4] = Dice[5];
			Dice[5] = Dice[1];
			Dice[1] = temp;
		}
		if (dir == 'E') {
			temp = Dice[0];
			Dice[0] = Dice[3];
			Dice[3] = Dice[5];
			Dice[5] = Dice[2];
			Dice[2] = temp;
		}
		if (dir == 'W') {
			temp = Dice[0];
			Dice[0] = Dice[2];
			Dice[2] = Dice[5];
			Dice[5] = Dice[3];
			Dice[3] = temp;
		}
	}
};

int main()
{
	int n, fr, up, count = 0;
	char dir;
	DiceMove move;
	std::string direction;
	for (int i = 0; i < 6; i++)
		std::cin >> Dice[i];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> up >> fr;
		while (1) {
			if (Dice[1] == up && Dice[0] == fr) {
				move.Move('W');
				move.Move('W');
				move.Move('N');
			}
			if (Dice[0] == up && Dice[1] == fr) break;
			else {
				if (count == 3) {
					move.Move('W');
					count = 0;
				}
				else {
					move.Move('N');
					count++;
				}
			}
		}
		std::cout << Dice[2] << std::endl;
		count = 0;
	}
	return 0;
}