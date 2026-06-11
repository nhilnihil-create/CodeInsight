#include <iostream>
using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;
	int prize = 0;
	if (X <= 3) prize += (4 - X) * 100000;
	if (Y <= 3) prize += (4 - Y) * 100000;
	if (X == 1 && Y == 1) prize += 400000;
	cout << prize << endl;
}