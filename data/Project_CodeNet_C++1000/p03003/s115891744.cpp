#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,m;cin>>n>>m;
    vector<ll>s(n);
    vector<ll>t(m);
    rep(i,n){
        cin>>s[i];
    }
    rep(i,m){
        cin>>t[i];
    }
    vector<vector<ll> >dp(n,vector<ll>(m));
    if(s[0]==t[0])dp[0][0]=2;
    else dp[0][0]=1;
    REP(i,1,n){
        if(s[i]==t[0])dp[i][0]=(dp[i-1][0]+1)%inf;
        else dp[i][0]=dp[i-1][0];
    }
    REP(i,1,m){
        if(s[0]==t[i])dp[0][i]=(dp[0][i-1]+1)%inf;
        else dp[0][i]=dp[0][i-1]%inf;
    }
    REP(i,1,n){
        REP(j,1,m){
            if(s[i]==t[j])dp[i][j]=(dp[i][j-1]+dp[i-1][j])%inf;
            else{
                dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1])%inf;
            }
        }
    }
    if(dp[n-1][m-1]<0)dp[n-1][m-1]+=inf;
    cout<<dp[n-1][m-1]<<endl;
}