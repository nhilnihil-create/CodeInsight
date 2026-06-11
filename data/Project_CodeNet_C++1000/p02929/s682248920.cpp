#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 1000000007

int main() {
	ll N;
	string S;
	cin >> N;
	cin >> S;
	vector<ll> A(N * 2, 1), B = A;
	for (int i = 0;i < N * 2;i++) {
		if (i % 2) {
			if (S[i] == 'B')
				A[i] = -1;
		}
		else if (S[i] == 'W')
				A[i] = -1;
	}
	for (int i = 1;i < 2 * N;i++) {
		if (A[i] == -1)
			B[i] = A[i - 1];
		A[i] += A[i - 1];
		if (A[i] < 0) {
			B[0] = 0;
			break;
		}
	}
	if (A[2 * N - 1])B[0] = 0;
	if (A[0] < 0)B[0] = 0;
	ll ans = 1;
	for (ll i : B) {
		ans *= i;
		ans %= MOD;
	}
	ll kaij = 1;
	for (ll i = 1;i <= N;i++)(kaij *= i) %= MOD;
	cout << ans * kaij%MOD << endl;
}