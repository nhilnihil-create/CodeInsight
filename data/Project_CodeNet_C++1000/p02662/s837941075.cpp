//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, s, dp[maxn][maxn], p2;

int main(){
	fast_io;
	
	p2 = (mod + 1) / 2;
	cin >> n >> s;
	dp[0][0] = 1;
	for(ll i = 1; i <= n; i++){
		cin >> a;
		for(ll j = 0; j < maxn; j++){
			dp[i][j] = dp[i - 1][j];
			if(j >= a) dp[i][j] = (dp[i][j] + dp[i - 1][j - a] * p2) % mod;
		}
	}
	s = dp[n][s];
	for(ll i = 0; i < n; i++){
		s = (s * 2) % mod;
	}
	cout << s;
	
	return 0;
}
