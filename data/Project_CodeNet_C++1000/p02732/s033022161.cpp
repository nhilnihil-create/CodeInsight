#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

ll comb(ll a) {
	return a * (a - 1) / 2;
}

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	vector<bool> ok(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	map<ll, ll> M;
	for (int i = 0; i < N; i++) {
		if (M[A[i]] >= 1) ok[i] = true;
		M[A[i]]++;
	}
	ll s = 0;
	for (int i = 0; i < N; i++) {
		if (ok[i]) continue;
		s += comb(M[A[i]]);
	}
	for (int i = 0; i < N; i++) {
		cout << s - comb(M[A[i]]) + comb(M[A[i]] - 1) << endl;
	}
	return 0;
}