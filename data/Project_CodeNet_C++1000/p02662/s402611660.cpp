#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
// #define endl '\n'
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(0);
#define show(x) cout<<x<<endl;
#define pret(x) cout<<x<<endl; return 0;
#define disp(x) cout<<x<<" ";
#define let(x,y) cout<<x<<" "<<y<<endl;
ll MOD=998244353;
const int maxn=3e3+5;

int dp[maxn][maxn];

int32_t main(){
    fast_io;
    int n,s;
    cin>>n>>s;
    int a[n+1];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i+1];
    }
    dp[0][0] = 1;
    fo(i,1,n){
    	for (int j = 0; j+a[i] < maxn; ++j)
    	{
    		dp[i][j+a[i]] = dp[i-1][j];
    	}
    	for (int j = 0; j < maxn; ++j)
    	{
    		dp[i][j] = (dp[i][j] + 2*dp[i-1][j])%MOD;
    	}
    }
    show(dp[n][s]);
    return 0;
}