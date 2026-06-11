#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k;
	cin >> n >> k;

	vl a(n+2);
	FOR(i,1,n+1) cin >> a[i];
	n += 2;

	vvl dp(n,vl(k+1,oo));
	dp[0][0] = 0;

	FOR(i,1,n) FOR(j,0,k+1) FOR(ii,0,i) {
		ll jj = j - (i-ii-1);
		if (jj < 0) continue;

		dp[i][j] = min(dp[i][j], dp[ii][jj] + max(a[i]-a[ii],0LL));
	}
	
	ll res = *min_element(all(dp[n-1]));
	cout << res << endl;
}

