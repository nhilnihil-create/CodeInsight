#include <bits/stdc++.h>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
const int N=1e4+100;
int s[N],t[N];
ll dp[N][N];
int mod=1e9+7;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int j=1;j<=m;j++) cin>>t[j];
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=0;i<=m;i++) dp[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1])%mod;
            if(s[i]==t[j])
            dp[i][j]=(dp[i][j]+dp[i-1][j-1]+mod)%mod;
        }
    }
    printf("%lld\n",(dp[n][m]+mod)%mod);
    return 0;
}
