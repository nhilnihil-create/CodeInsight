#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 123;
#define int long long 
int n, m;
pair <int, int> a[maxn];
string s[60], t[60];
int dp[2][5005];
main () { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i <= 1; i++)
    for(int j = 0; j < 5000; j++)
    	dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++) {
    	int cost, b;
    	int msk = 0;
    	cin >> cost >> b;
    	for(int j=  0; j < b; j++) {
    		int x;
    		cin >> x;
    		x--;
    		msk |= 1 << x;
    	}
    	int cur = i % 2;
    	int prev = cur ^ 1;

    	for(int j = 0; j < (1 << n); j++) {
    		dp[cur][j] = min(dp[cur][j], dp[prev][j]);
    		dp[cur][j | msk] = min(dp[cur][j | msk], dp[prev][j] + cost);
    	}
    	for(int j = 0; j < (1 << n) ; j++)
    		dp[prev][j] = 1e9;
    }
    if(dp[m % 2][(1 << n) - 1] >= 1e9) cout << -1;
    else cout << dp[m % 2][(1 << n) - 1];
}


