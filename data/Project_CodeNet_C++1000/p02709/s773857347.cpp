#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<int, int> P;
typedef tuple<int, int, int> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

const ll mod = 1000000007;

int main() {
	ll n;
	cin >> n;
	vector<P> as(n);
	rep(i, n) { 
		ll a;
		cin >> a;
		as[i] = { a,i };
	}
	sort(as.begin(), as.end(), greater<P>());
	vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
	//数値が大きい順に先頭か、末端に配置すればよい
	//左からi人埋めて、右からj人埋めたときのスコア=dp[i][j]
	//dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + as[i].first  * (as[i].second - j)
	for(ll i = 0;i < n;i++){
		for (ll left = 0; i-left >= 0;left++) {
			//dp[left][right] から dp[left+1][right], dp[left][right+1]にpush
			ll right = i - left;
			ll n1 = left + 1;
			ll add1 = as[i].first * abs(as[i].second - left);
			dp[n1][right] = max(dp[n1][right], dp[left][right] + add1);
			ll n2 = right + 1;
			ll add2 = as[i].first * abs(as[i].second - (n-1 - right));
			dp[left][n2] = max(dp[left][n2], dp[left][right] + add2);
		}
	}
	ll u = 0;
	rep(i, n + 1) {
		rep(j, n + 1) {
			u = max(u, dp[i][j]);
		}
	}
	cout << u << endl;
	return 0;
}
