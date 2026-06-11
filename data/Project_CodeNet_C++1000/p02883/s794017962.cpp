#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll INF = 10010010010010;

int main() {
	ll N, K;
	cin >> N >> K;

	vector <ll> A(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> A[ii];
	}
	sort(A.begin(), A.end());

	vector <ll> F(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> F[ii];
	}
	sort(F.rbegin(), F.rend());

	//二分探索
	ll l = -1;
	ll r = INF;
	while(l+1 < r) {
		ll mid = (l + r) / 2;
		ll sum = 0;
		for (int ii = 0; ii < N; ++ii){
			sum += max(0LL, A[ii] - mid / F[ii]);
		}
		if (sum <= K){
			r = mid;
		} else {
			l = mid;
		}
	}

	cout << r << "\n";

	return 0;
}
