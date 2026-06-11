//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 100000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000010;
const ll LOG = 25;

ll n, a[N], dp[N];
int res, ans;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i <= n; i++) cin >> a[i];
	dp[0] = 1;
	if (a[0] > 1) return cout << -1, 0;
	for (int i = 1; i <= n; i++){
		dp[i] = min(INF, (dp[i - 1] - a[i - 1]) * 2);
//		cout << dp[i] << '\n';
		if (dp[i] < a[i]) return cout << -1, 0;
	} 
	ll ans = a[n];
	for (int i = n - 1; i >= 0; i--){
		a[i] = min(dp[i] - a[i], a[i + 1]) + a[i];
//		cout << i << ' ' << a[i] << '\n';
		ans += a[i]; 
	}
	cout << ans;








	return 0;
}
