#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define INF 10000000000



int main(){
    int N,M; cin>>N>>M;
    vector<vector<ll>> dp(M+1,vector<ll>(1<<12,INF));
    dp[0][0] = 0;
    rep(i,M){
        ll a,b; cin>>a>>b;
        vector<ll> c(b);
        int add = 0;
        rep(j,b){
            cin>>c[j];
            c[j]--;
            add |= (1<<c[j]);
        }
        //i個目の鍵を使わないとき
        for(int bit = 0; bit < (1<<N); bit++){
            dp[i+1][bit] = min(dp[i][bit],dp[i+1][bit]);
            dp[i+1][bit|add] = min(dp[i+1][bit|add],dp[i][bit]+a);
        }
    }
    cout<<((dp[M][(1<<N)-1]==INF)?-1:dp[M][(1<<N)-1])<<endl;
}