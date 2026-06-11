#include <iostream>

using namespace std;

class Dice {
private:
	int number[6];
public:
	void setNumber(int index, int num);
	void move(string d);
	int getTop();
};

void Dice::setNumber(int index, int num) {
	number[index] = num;
}

void Dice::move(string d) {
	int oldIndex[4][6] = {
		{1, 5, 2, 3, 0, 4},
		{3, 1, 0, 5, 4, 2},
		{2, 1, 5, 0, 4, 3},
		{4, 0, 2, 3, 5, 1},
	};
	for (int i = 0; i < d.size(); i++) {
		int newNumber[6] = {0};
		int *idx;
		char c = d[i];
		switch (c) {
			case 'N': idx = oldIndex[0]; break;
			case 'E': idx = oldIndex[1]; break;
			case 'W': idx = oldIndex[2]; break;
			case 'S': idx = oldIndex[3]; break;
			default: return;
		}
		for (int i = 0; i < 6; i++)
			newNumber[i] = number[idx[i]];
		for (int i = 0; i < 6; i++)
			number[i] = newNumber[i];
	}
}

int Dice::getTop() {
	return number[0];
}

int main() {
	Dice dice;
	int n;
	for (int i = 0; i < 6; i++) {
		cin >> n;
		dice.setNumber(i, n);
	}
	string s;
	cin >> s;
	dice.move(s);
	cout << dice.getTop() << endl;
	return 0;
}