#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

int main() {
	int N;
	cin >> N;
	vector<int> C(N + 1);
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		C[A]++;
	}
	vector<int> D(N + 1);
	for (int i = 1; i <= N; i++) {
		D[C[i]]++;
	}
	for (int i = 1; i <= N; i++) D[i] += D[i - 1];
	vector<int> sum(N + 1);
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + (N - D[i - 1]);
	}
	vector<int> ans(N + 1);
	int x = 0;
	for (int k = N; k >= 1; k--) {
		while (x < N) {
			if (sum[x + 1] >= k * (x + 1)) x++;
			else break;
		}
		ans[k] = x;
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << endl;
}