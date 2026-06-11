#include<iostream>
using namespace std;
long long int a[200000];
int main() {
	//B
	int n;
	cin >> n;

	long long int bou = 0, habou = 0;
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		bou = bou + a[i];
	}
	for (i = 0; i < n; i++) {
		habou = habou + a[i];
		if (habou * 2 >= bou)break;
	}
	if (bou - (habou - a[i]) * 2 < habou * 2 - bou) {
		cout << bou - (habou - a[i]) * 2;
	}
	else {
		cout << habou * 2 - bou;
	}

	return 0;


	//A
	/*int money = 0;
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
	*/
}