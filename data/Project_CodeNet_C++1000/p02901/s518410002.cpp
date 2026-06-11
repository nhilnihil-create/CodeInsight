#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const int INF = 1LL<<30;

int takara[1010];
int dp[1010][1<<12];

int main() {
    int N,M;
    cin>>N>>M;
    vector<int> A(M),B(M);
    rep(i,M){
        cin>>A[i]>>B[i];
        rep(j,B[i]){
            int c;
            cin>>c;
            c--;
            takara[i] |= 1 << c;
        }
    }

    rep(i,M+1) rep(msk,1<<N) dp[i][msk]=INF;
    dp[0][0]=0;

    rep(i,M) rep(msk,1<<N){
        dp[i+1][msk]=min(dp[i+1][msk],dp[i][msk]);
        dp[i+1][msk | takara[i]]=min(dp[i+1][msk | takara[i]],dp[i][msk]+A[i]);
    }

    int ans=dp[M][(1<<N)-1];
    if(ans==INF) ans=-1;
    
    cout<<ans<<endl;
}