#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
int main(void){
    ll n;cin>>n;
    //vector<vector<ll>> dp(n+10,vector<ll>(3,0));
    vector<ll> dp(3,0);
    ll res=1;
    vector<ll> x(n);
    rep(i,n){
        cin>>x[i];
    }
    rep(i,n){
        //cout<<x[i]<<endl;
        ll buf=0;
        bool jud=false;
        rep(j,3){
            if(dp[j]==x[i]){
                buf++;
                if(!jud){
                    jud=true;
                    dp[j]++;
                }
            }
        }
        res*=buf;
        res%=mod;
        //cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<endl;
    }
    cout<<res<<endl;
}