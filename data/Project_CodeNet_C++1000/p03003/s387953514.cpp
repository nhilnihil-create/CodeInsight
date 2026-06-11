#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1+1e4;
const int mod =1e9+7;
int n,m,a[MAXN],b[MAXN],f[MAXN][MAXN];

int main()
{
#define TASK "ABC"
    //freopen(TASK ".inp","r",stdin);
   // freopen(TASK ".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i) cin>>b[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
        if(a[i-1]==b[j-1]) f[i][j]=(1+f[i][j-1]+f[i-1][j])%mod;
        else {
            f[i][j]=(f[i][j-1]+f[i-1][j]-f[i-1][j-1])%mod;
        }

        f[i][j]=(f[i][j]+mod)%mod;
    }
    }
    cout<<f[n][m]+1;
    return 0;
}
