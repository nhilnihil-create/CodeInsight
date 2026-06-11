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
    ll h,n;cin>>h>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    vector<vector<ll> >dp(n+1,vector<ll>(h+1,mod*mod));
    dp[0][0]=0;
    rep(i,n){
        rep(j,h+1){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            if(j+a[i]<=h){
                dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i][j]+b[i]);
            }else{
                dp[i][h]=min(dp[i][h],dp[i][j]+b[i]);
            }
        }
    }
    cout<<dp[n][h]<<endl;
}