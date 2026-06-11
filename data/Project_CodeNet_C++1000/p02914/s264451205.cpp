#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
ll A[100000];
int main() {
	int N;
	cin >> N;
	ll all = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		all ^= A[i];
	}
	for (int i = 0; i < N; i++) A[i] &= ~all;
	int r = 0;
	for (int i = 59; i >= 0; i--) {
		int idx = -1;
		for (int j = r; j < N; j++) {
			if (A[j] & (1LL << i)) {
				idx = j;
				break;
			}
		}
		if (idx == -1) continue;
		swap(A[r], A[idx]);
		for (int j = 0; j < N; j++) {
			if (j == r) continue;
			if (A[j] & (1LL << i)) A[j] ^= A[r];
		}
		r++;
	}
	ll ans = 0;
	for (int i = 0; i < r; i++) ans ^= A[i];
	ans = ans * 2 + all;
	cout << ans << endl;
}