#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(void){
	int n;
	int *score;
	double ave, S;

	while (true){
		cin >> n;

		if (n == 0) break;

		score = new int[n];

		S = ave = 0.0;
		for (int i = 0; i < n; i++){
			cin >> score[i];
			ave += score[i];
		}
		ave /= n;
	
		for (int i = 0; i < n; i++){
			S += (score[i] - ave)*(score[i] - ave);
		}

		cout << fixed << setprecision(10) << sqrt(S / n) << "\n";

		delete[] score;
	}

	return 0;
}