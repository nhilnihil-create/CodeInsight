#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	vector<long long> An;
	cin >> N ;
	for (int n = 0;n <= N;++n) {
		long long m;
		cin >> m;
		An.push_back(m);
	}
	vector<long long> Bn;
	//A0 + B0 = 1
	//Bd <= Ad+1 + Bd+1 <=2Bd
	//Bd <= Ad+1,,,,,,,,,,AN

	vector<long long> Cn; //N + 1 - nから最後まで足す
	Cn.push_back(0);
	for (int m = 1; m <= N; ++m) {
		Cn.push_back(Cn[m-1]+An[N-m+1]);
	}
	if (N == 0) {
		if (1 != An[0]) {
			cout << -1 << endl;
		}
		else {
			cout << 1 << endl;
		}
		return 0;
	}

	if (0 != An[0]) {
		cout << -1 << endl;
		return 0;
	}
	Bn.push_back(1-An[0]);

	for (int n = 1; n <= N; ++n) {
		long long min = Bn[n-1] - An[n];
		long long max1 = 2 * Bn[n-1] - An[n];
		long long max2 = Cn[N-n];
		if (max2 < min) {
			cout << -1 << endl;
			return 0;
		}
		long long max = 0;
		if (max2 > max1) {
			max = max1;
		}
		else {
			max = max2;
		}

		if (max >= 0) {
			Bn.push_back(max);
		}
		else {
			cout << -1 << endl;
			return 0;
		}
	}

	long long nAns = 0;
	for (int n = 0; n <= N; ++n) {
		nAns += An[n];
		nAns += Bn[n]; 
	}
	cout << nAns << endl;


	return 0;
}
