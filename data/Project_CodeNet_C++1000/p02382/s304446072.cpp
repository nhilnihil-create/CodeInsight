
#include<iostream>
#include<string>
#include<algorithm>
#define _USE_MATH_DEFINES
#include<math.h>
#include<iomanip>

using namespace std;

int main() {
	double man=0,you=0,tye=0,po3=0;
	int n, i;
	int box1[100] = {};
	int box2[100] = {};

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> box1[i];
	}
	for (i = 0; i < n; i++) {
		cin >> box2[i];
	}
	for (i = 0; i < n; i++) {
		man += fabs(box1[i] - box2[i]);
		if (tye < fabs(box1[i] - box2[i])) {
			tye = fabs(box1[i] - box2[i]);
		}
	}
	for (i = 0; i < n; i++) {
		you += (box1[i] - box2[i]) * (box1[i] - box2[i]);
	}
	
	for (i = 0; i < n; i++) {
		po3 += fabs(box1[i] - box2[i]) * fabs(box1[i] - box2[i]) * fabs(box1[i] - box2[i]);
	}

	cout << fixed << setprecision(6)<<man << endl;
	cout << fixed << setprecision(6) << sqrt(you) << endl;
	cout << fixed << setprecision(6) << pow(po3,1.0/3.0) << endl;
	cout << fixed << setprecision(6) << tye << endl;

	return 0;
}

