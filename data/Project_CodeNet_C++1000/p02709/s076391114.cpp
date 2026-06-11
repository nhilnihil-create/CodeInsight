#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <ll,int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const int N = 200005;

ll dp[2005][2005];

void solve(){
	ll n;
	cin >> n;
	vector<ii> v;
	for(int i = 1; i <= n; i++){
		ll x; cin >> x;
		v.pb({x, i});
	}
	sort(v.rbegin(), v.rend());
	for(int i = 1; i <= n; i++){
		ll val = v[i-1].fst, pos = v[i-1].snd;
		for(int j = 0; j < i; j++){
			ll l = j, r = i - 1 - j; // elements in the left and right corner
			dp[l+1][r] = max(dp[l+1][r], dp[l][r] + val * abs(l+1ll-pos));
			dp[l][r+1] = max(dp[l][r+1], dp[l][r] + val * abs(n-r-pos));
			l = i - 1 - j, r = j;
			dp[l+1][r] = max(dp[l+1][r], dp[l][r] + val * abs(l+1ll-pos));
			dp[l][r+1] = max(dp[l][r+1], dp[l][r] + val * abs(n-r-pos));
		}
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++){
		ans = max(ans, dp[i][n-i]);
	}
	cout << ans << endl;
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
