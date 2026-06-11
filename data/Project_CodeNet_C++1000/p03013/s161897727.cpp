#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

ll dp[110000];
bool fall[110000];

int main() {

	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a;
		cin >> a;
		fall[a] = true;
	}
	dp[0] = 1;
	rep(i, n + 1) {
		if (!fall[i + 1])dp[i + 1] += dp[i];
		if (!fall[i + 2])dp[i + 2] += dp[i];
		dp[i + 1] %= MOD;
		dp[i + 2] %= MOD;
	}
	cout << dp[n] << endl;
}