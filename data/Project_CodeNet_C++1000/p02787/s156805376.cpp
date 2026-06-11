//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
//using Graph = vector<vector<int>>;
typedef long long ll;
using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll h,n; cin>>h>>n;
    vector<ll>dp(h+1,INF);
    dp[0]=0;
    rep(i,n){
        ll a,b; cin>>a>>b;
        rep(j,h+1){
            int idx=min(j+a,h);
            dp[idx]=min(dp[idx],dp[j]+b);
        }

    }
    cout<<dp[h]<<endl;
}









