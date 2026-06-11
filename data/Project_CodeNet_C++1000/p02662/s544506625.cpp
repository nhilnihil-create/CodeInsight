#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int mod = 998244353, maxn = 3010;
int dp[maxn][maxn];

void solve(){
	
	int n, s;
	cin >> n >> s;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	
	dp[0][0] = 1;
	for(int pos = 0; pos < n; pos++){
		for(int soma = 0; soma <= s; soma++){
			if(soma + a[pos] <= s){
				dp[pos+1][soma+a[pos]] += dp[pos][soma];
				dp[pos+1][soma+a[pos]] %= mod;
			}
			
			dp[pos+1][soma] += 2*dp[pos][soma];
			dp[pos+1][soma] %= mod;
		}
	}
	
	cout << dp[n][s] << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	//cin >> tc;
	while(tc--)
		solve();
}
