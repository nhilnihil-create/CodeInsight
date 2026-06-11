#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> A(N);
	for (ll ii = 0; ii < N; ++ii){
		cin >> A[ii];
	}
	A.push_back(0);

	ll m = 1000;
	ll s = 0;
	for (ll ii = 0; ii < N; ++ii){
		m += s*A[ii];
		s = 0;
		if (A[ii] < A[ii+1]){
			s = m / A[ii];
			m -= s*A[ii];
		}
	}

	cout << m << "\n";

	return 0;
}
