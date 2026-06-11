#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int dp[1010][1<<12];
int takara[1010];

int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    rep(i,m){
        cin>>a[i]>>b[i];
        rep(j,b[i]){
            int c;
            cin>>c;
            c--;
            takara[i]|=1<<c;
        }  
    }

    rep(i,m+1) rep(msk,1<<n) dp[i][msk]=INF;
    dp[0][0]=0;

    rep(i,m) rep(msk,1<<n){
        dp[i+1][msk]=min(dp[i+1][msk],dp[i][msk]);
        dp[i+1][msk | takara[i]]=min(dp[i+1][msk | takara[i]],dp[i][msk]+a[i]);
    }

    int ans=dp[m][(1<<n)-1];
    if(ans==INF) ans=-1;
    cout<<ans<<endl;
}
