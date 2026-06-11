#include<iostream>
using namespace std;
int main() {
	//B




	//A
	int money = 0;
	int x, y;
	cin >> x >> y;
	if (x == 1 && y == 1)
		money = 1000000;
	else 
	{
		if (x <= 3) {
			money = (4 - x) * 100000;
		}
		if (y <= 3) {
			money = money + (4 - y) * 100000;
		}
	
	}
	cout << money << endl;
	return 0;
	
}