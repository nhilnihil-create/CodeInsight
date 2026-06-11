#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}

const int MAXN = 2e3 + 5, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return ll(x) * y % MOD;
}

inline int inv(int x) {
	int y = MOD - 2;
	int ret = 1;
	while(y) {
		if (y&1) ret = mul(ret, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ret;
}

inline int divi(int x, int y) {
	return mul(x, inv(y));
}

int n, m;
int a[MAXN];
int b[MAXN];

int memo[MAXN][MAXN];
int main() {
	int n, m; rd(n); rd(m);

	for (int i = 1; i <= n; i++) rd(a[i]);
	for (int i = 1; i <= m; i++) rd(b[i]);

	int ans = 1;
	for (int i = 0; i <= n; i++) memo[i][0] = 1;
	for (int j = 0; j <= m; j++) memo[0][j] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			memo[i][j] = add(memo[i][j-1], memo[i-1][j]);
			memo[i][j] = sub(memo[i][j], memo[i-1][j-1]);
			if (a[i] == b[j]) {
				ans = add(ans, memo[i-1][j-1]);
				memo[i][j] = add(memo[i][j], memo[i-1][j-1]);
			}

		}
	}

	printf("%d\n", ans);	
}