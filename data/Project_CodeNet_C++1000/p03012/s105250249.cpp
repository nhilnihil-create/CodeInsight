#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	int N; cin >> N;
	vector<int> W(N);
	rep(i, N)cin >> W[i];
	int s1 = W[0];
	int s2 = accumulate(W.begin() + 1, W.end(), 0);
	int ans = abs(s1 - s2);
	rep(i, N - 1) {
		s1 += W[i + 1];
		s2 -= W[i + 1];
		int dif = abs(s1 - s2);
		if (ans > dif)ans = dif;
	}
	cout << ans;
}