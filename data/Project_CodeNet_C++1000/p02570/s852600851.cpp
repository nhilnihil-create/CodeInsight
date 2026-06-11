#include<iostream>
using namespace std;

int main() {

	int D = 0;
	int T = 0;
	int S = 0;

	double time = 0;//到着までにかかる時間

	do {

		cin >> D >> T >> S;

	} while ( D < 1 || D > 10000 || T < 1 || T > 10000 || S < 1 || S > 10000);

	time = (double)D/ (double)S;

	if (T >= time) {

		cout << "Yes" << endl;

	}
	else {

		cout << "No" << endl;

	}

	return 0;

}