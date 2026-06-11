#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int dp[1010][10010];

int main(){
    int h,n;
    cin>>h>>n;
    vector<int> a(n),b(n);
    rep(i,n) cin>>a[i]>>b[i];

    rep(i,1010) rep(j,10010) dp[i][j]=INF;
    dp[0][0]=0;

    rep(i,n){
        for(int w=0;w<=h;w++){
            dp[i+1][w]=min(dp[i+1][w],dp[i][w]);
            dp[i+1][min(h,w+a[i])]=min(dp[i+1][min(h,w+a[i])],dp[i+1][w]+b[i]);
        }
    }

    cout<<dp[n][h]<<endl;

}
