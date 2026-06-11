#include<bits/stdc++.h>
 
using namespace std;
 
#define D(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;

lli dp[2003][2003];

int main()
{
    int s;
    cin >> s;
    lli ans = 0, mod = 1e9+7;
    for(int i=3; i<=2002; i++){
		dp[1][i] = 1;
	} 
	for(int i=2; i<=2000; i++){
		lli sm = 0;
		for(int j=3; j<=2000; j++){
			sm = (sm+dp[i-1][j-3])%mod;
			dp[i][j] = sm;
		}
	}
	for(int i=1; i<=2000&&s>=0; i++){
		ans = (ans+dp[i][s])%mod;
	}
	cout << ans << endl;

 
    return 0;
}
