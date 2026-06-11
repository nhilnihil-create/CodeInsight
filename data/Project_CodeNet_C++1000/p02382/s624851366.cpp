#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
		int n;
		int date_x[100];
		int date_y[100];
		double sum = 0;
		double var = 0;
		double D[4] = { 0 };
		string haki;
		cin >> n;
		getline(cin, haki);
		for (int i = 0; i < n; i++) {
			cin >> date_x[i];
		}
		getline(cin, haki);
		for (int i = 0; i < n; i++) {
			cin >> date_y[i];
		}
		getline(cin, haki);
		for (int i = 0; i < n; i++) {
			D[0] += abs(date_x[i] - date_y[i]);
			D[1] += pow(abs(date_x[i] - date_y[i]), 2);
			D[2] += pow(abs(date_x[i] - date_y[i]), 3);
			if(D[3] < abs(date_x[i] - date_y[i]))D[3] = abs(date_x[i] - date_y[i]);
		}
		D[1] = pow(D[1], 1.0 / 2.0);
		D[2] = pow(D[2], 1.0 / 3.0);

		for (int i = 0; i < 4; i++) {
			cout << fixed << D[i] << endl;
		}

	return 0;
}
