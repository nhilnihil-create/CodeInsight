#include<iostream>

using namespace std;

int calcurate(int cal[20],int i,int krg,int j) {
	if (j == 1) {
		/*for (int i = 1; i <= 20; i++) {
			cout << cal[i] << endl;
		}*/
		return cal[20];
	}
	cal[j] = (cal[j] * i);
	cal[j] += krg;
	if (cal[j] >= 10) {
		int tmp;
		tmp = int(cal[j] / 10);
		cal[j] %= 10;
		krg = tmp;	/*繰り上げ*/

	}
	else {
		krg = 0;
	}
	calcurate(cal, i, krg, j - 1);


}

int main() {
	int n, cal[21] = {0};
	cal[20] = 1;
	cin >> n;
	int krg = 0;
	for (int i = 1; n >= i; i++) {
		int j = 20;
		calcurate(cal, i, krg, j);


	}
	int x = 1;
	while (true) {
		if (cal[x] != 0) {
			break;
		}
		x += 1;
	}
	for (int i = x; i <= 20; i++) {
		cout << cal[i];
	}
	cout << endl;


}
	
