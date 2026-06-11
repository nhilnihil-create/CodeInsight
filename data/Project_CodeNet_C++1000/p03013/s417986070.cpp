#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=998244353;
const ll mod=1e9+7;
signed main(){
    ll n,m;cin>>n>>m;
    vector<ll>a(n+3);
    vector<ll>dp(n+3);
    rep(i,m){
        ll b;cin>>b;
        a[b]=1;
    }
    dp[0]=1;
    rep(i,n){
        if(a[i])continue;
        dp[i+1]=(dp[i+1]+dp[i])%mod;
        dp[i+2]=(dp[i+2]+dp[i])%mod;
    }
    cout<<dp[n]<<endl;
}