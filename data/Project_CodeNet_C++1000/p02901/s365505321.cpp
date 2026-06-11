#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int n, m;
vi a, b;
vvi c;
int memo[1020][1 << 13];

int dp(int i, int j) {
	if (memo[i][j] != 0)return memo[i][j];
	if (j == 0)return 0;
	if (i == 0)return INF;
	
	int k1 = dp(i - 1, j);

	int jj = 0;
	rep(l, b[i - 1])jj += (1 << (c[i - 1][l] - 1));
	int jjj = 0;
	rep(l, n) if ((j >> l & 1) && !(jj >> l & 1))jjj += 1 << l;
	
	int k2 = dp(i - 1, jjj);
	memo[i][j] = min(k1, k2 + a[i - 1]);
	return memo[i][j];

}

int main() {

	cin >> n >> m;
	a.resize(m);
	b.resize(m);
	c.resize(m);

	rep(i, m + 1)rep(j, 1 << n)memo[i][j] = 0;

	rep(i, m) {
		cin >> a[i] >> b[i];
		c[i].resize(b[i]);
		rep(j, b[i])cin >> c[i][j];
	}

	int ans = dp(m, ((1 << n) - 1));
	if (ans == INF)cout << -1 << endl;
	else cout << ans << endl;

}