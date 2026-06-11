//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,m; cin>>n>>m;
    vector<ll> s(n,0),t(m,0),dp(m+1,0);
    dp[0]=1;
    rep(i,n) cin>>s[i];
    rep(i,m) cin>>t[i];
    rep(i,n){
        ll cnt=1;
        rep(j,m){
            ll temp=dp[j+1];
            if(s[i]==t[j]){
                dp[j+1]=(dp[j+1]+cnt)%MOD;
            }
            cnt=(cnt+temp)%MOD;
        }
    }
    ll ans=0;
    rep(i,m+1) ans=(ans+dp[i])%MOD;
    cout<<(ans+MOD)%MOD<<endl;
}