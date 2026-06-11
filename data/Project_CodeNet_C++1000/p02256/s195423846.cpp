#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int num = 0;
int uclide(int x,int y) {
	if (y == 0) return x;
	else {
		num = x;
		x = y;
		y = num%y;
		uclide(x, y);
	}
}
int main() {
	int x, y;
	int a = 0;
	cin >> x;
	cin >> y;
	if (x < y) {
		num = x;
		x = y;
		y = num;
	}
	a = uclide(x, y);
	cout << a << endl;
	return 0;
}