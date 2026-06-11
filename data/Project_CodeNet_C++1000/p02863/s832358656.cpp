#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,t;cin>>n>>t;
    vector<pair<ll,ll>> p(n);
    rep(i,n){
        cin>>p[i].first>>p[i].second;
    }
    sort(p.begin(),p.end());
    vector<ll> dp(4000,-1);
    dp[0]=0;
    ll res=0;
    
    rep(i,n){
        int a=p[i].first,b=p[i].second;
        ll buf=0;
        rep(j,t)if(dp[j]!=-1)chmax(buf,dp[j]);
        chmax(res,buf+b);
        for(int j=3999;j>=0;j--){
            if(dp[j]!=-1&&j+a<4000){
                chmax(dp[j+a],dp[j]+b);
            }
        }
    }
    rep(i,t+1){
        chmax(res,dp[i]);
    }
    cout<<res<<endl;
}
