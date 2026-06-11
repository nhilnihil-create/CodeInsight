#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 998244353;
const ll inf = 922337203685477;
const ll mininf = -922337203685477;
const ll nax = 0;

ll n, s, dp[3005][3005], a[3005];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> s;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[0][0] = 1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= s; j++){
			dp[i][j] += 2 * dp[i-1][j];
			dp[i][j] %= mod;
			if(j + a[i] <= s){
				dp[i][j+a[i]] += dp[i-1][j];
				dp[i][j+a[i]] %= mod;
			}
		}
	}
	cout << dp[n][s] << '\n';
}
