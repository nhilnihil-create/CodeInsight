#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	vector <ll> d(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> d[ii];
	}

	ll sum = 0;
	for (int ii = 0; ii < N-1; ++ii){
		for (int jj = ii + 1; jj < N; ++jj){
			sum += d[ii]*d[jj];
		}
	}


		cout << sum << "\n";		

	return 0;
}
