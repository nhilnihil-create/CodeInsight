#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 2e3+10;

int n, m;
int a[maxn];
int b[maxn];
ll dp[maxn][maxn];//dp[i][j]: #of subseq ending at a[i] and b[j]

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
	cin>>a[i];
    }
    for (int i=1; i<=m; i++) {
	cin>>b[i];
    }

    ll ans=1;
    //dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
	for (int j=1; j<=m; j++) {
	    if (a[i]==b[j]) {
		dp[i][j]=1;
		dp[i][j]+=dp[i-1][j-1];
		dp[i][j]%=mod;
		ans += dp[i][j];
		ans %= mod;
	    } else {
		dp[i][j]=0;
	    }

	    dp[i][j] += dp[i][j-1];
	    dp[i][j] += dp[i-1][j];
	    dp[i][j] -= dp[i-1][j-1];
	}
    }


    ans %= mod;
    ans += mod;
    ans %= mod;

    cout<<ans<<endl;
    return 0;
}
