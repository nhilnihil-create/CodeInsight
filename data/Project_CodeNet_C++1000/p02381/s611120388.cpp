#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
	int q = 0;
	while (1) {
		double n;
		double date[1000];
		double sum = 0;
		double var = 0;
		string haki;
		cin >> n;
		getline(cin, haki);
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			cin >> date[i];
			sum += date[i];
		}
		double ave = sum / n;
		for (int i = 0; i < n; i++) {
			var += pow(date[i] - ave, 2);
		}
		cout << fixed << pow(var / n,0.5) << endl;
		q++;
		if (q > 10)break;

	}
	return 0;
}
