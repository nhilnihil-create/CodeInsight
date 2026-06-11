#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define P 0
#define D 1
const char *ch = "PD";

int n;
char s[2 << 17];
int dp[2 << 17][2];
int pre[2 << 17][2];

int occ(int c0, int c1) {
	int ans = 0;
	if (c1 == D) ++ ans;
	if (c0 == P && c1 == D) ++ ans;
	return ans;
}

void prt(int i, int f) {
	if (!i) return ;
	prt(i - 1, pre[i][f]);
	putchar(ch[f]);
}

int	main() {
	scanf("%s", s);
	n = strlen(s);
	memset(dp, -0x3f, sizeof(dp));
	dp[0][D] = 0;
	rep(i, n) rep(f, 2) if (dp[i][f] >= 0) {
		rep(nf, 2) if (s[i] == '?' || s[i] == ch[nf]) {
			if (dp[i + 1][nf] < dp[i][f] + occ(f, nf)) {
				dp[i + 1][nf] = dp[i][f] + occ(f, nf);
				pre[i + 1][nf] = f;
			}
		}
	}
	int f = 0;
	if (dp[n][1] > dp[n][0]) f = 1;
	prt(n, f); puts("");
	return 0;
}
