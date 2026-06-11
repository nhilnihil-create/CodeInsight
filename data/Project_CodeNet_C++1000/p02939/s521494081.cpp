#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

const int N = 2e5 + 100;
const int K = 5;

int dp[N][K];
char s[N];

bool same(int s1, int l1, int s2, int l2) {
	if (l1 != l2 || !s1) return false;
	for (int i = 0; i < l1; ++i)
		if (s[s1 + i] != s[s2 + i]) return false;
	return true;
}

int main() {
	scanf ("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < K; ++k) {
			if (i < k) continue;
			for (int j = 1; j < K; ++j)
				if (i + j <= n && !same(i - k + 1, k, i + 1, j))
					dp[i + j][j] = max(dp[i + j][j], dp[i][k] + 1);
		}
	int out = 0;
	for (int k = 0; k < K; ++k)
		out = max(out, dp[n][k]);
	printf("%d\n", out);
	
	return 0;
}
