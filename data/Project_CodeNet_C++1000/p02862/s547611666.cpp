#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

// calculates nCr (1 <= r <= n <= 1e7)
const int MAX = 1e7;
long long f[MAX], finv[MAX], inv[MAX];
// initializes nCr
void initnCr() {
	f[0] = f[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		f[i] = f[i-1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
		finv[i] = finv[i-1] * inv[i] % MOD;
	}
}

ll nCr(int n, int r) {
	if (n < r) return 0;
	if (n < 0 || r < 0) return 0;
	return f[n] * (finv[r] * finv[n-r] % MOD) % MOD;
}

int main() {
	initnCr();
	int x, y;
	cin >> x >> y;
	if (2 * x - y < 0 || (2 * x - y) % 3 != 0 || 2 * y - x < 0 || (2 * y - x) % 3 != 0) cout << 0 << endl;
	else cout << nCr((2 * x - y) / 3 + (2 * y - x) / 3, (2 * y - x) / 3) << endl;
}