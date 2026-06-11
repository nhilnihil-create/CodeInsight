#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int dp[1100][10100];
 
int main(){
    int h,n;
    cin>>h>>n;
    vector<int> a(n),b(n);
    rep(i,n) cin>>a[i]>>b[i];

    rep(i,1100) rep(j,10100) dp[i][j]=INF;
    dp[0][0]=0;

    rep(i,n){
        for(int j=0;j<=h;j++){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            dp[i+1][min(h,j+a[i])]=min(dp[i+1][min(h,j+a[i])],dp[i+1][j]+b[i]);
        }
    }

    cout<<dp[n][h]<<endl;
}