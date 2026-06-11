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
    vector<ll> dp(10000,-1);
    dp[0]=0;
    ll res=0;
    
    rep(i,n){
        int a=p[i].first,b=p[i].second;
        for(int j=t-1;j>=0;j--){
                chmax(dp[j+a],dp[j]+b);
        }
    }
    rep(i,t+3001){
        chmax(res,dp[i]);
    }
    cout<<res<<endl;
}
