#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 998244353;
using ll = long long;
using namespace std;

ll dp[3050][3050];

int main(){
	int n; ll s;
	cin >> n >> s;
	vector<ll> a(n);
	for( auto &k : a ) cin >> k;
	dp[0][0] = 1;
	for( int i = 0; i < n; ++i ){
		for( int j = 0; j <= s; ++j ){
			dp[i+1][j] += 2*dp[i][j];
			dp[i+1][j] %= mod;
			if( j+a[i] <= s ){
				dp[i+1][j+a[i]] += dp[i][j];
				dp[i+1][j+a[i]] %= mod;
			}
		}
	}
	cout << dp[n][s] << endl;
}