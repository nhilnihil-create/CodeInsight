#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int dp[1010][20010];

int main(){
    int h,n;
    cin >> h >> n;
    vi a(n+1), b(n+1);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,1010) rep(j,20010) dp[i][j]=1e9;
    int max_a=*max_element(a.begin(),a.end());

    dp[0][0]=0;
    rep(i,n+1){
        rep(j,h+max_a+1){
            if(i!=0) dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if(j-a[i]>=0) dp[i][j]=min(dp[i][j],dp[i][j-a[i]]+b[i]);
        }
    }

    int ans=1e9;
    for(int i=0;i<max_a+1;i++){
        ans=min(ans,dp[n][h+i]);
    }
    cout << ans << endl;



}