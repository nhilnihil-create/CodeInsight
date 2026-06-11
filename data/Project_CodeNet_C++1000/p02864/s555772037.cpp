#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);i++)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> void chmin(T& t, const U& u){if(t>u)t=u;}
template<typename T,typename U> void chmax(T& t, const U& u){if(t<u)t=u;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T mpow(T a, T n) {
   T res = 1;
   for(;n;n>>=1) {
      if (n & 1) res = res * a;
      a = a * a;
   }
   return res;
}

//cin.tie(0);ios::sync_with_stdio(false);
//cout<<fixed<<setprecision(20);

vector<vector<map<ll,ll>>> dp(310,vector<map<ll,ll>>(310));

signed main(){
    ll n,k;cin>>n>>k;
    vector<ll> h(n);rep(i,0,n)cin>>h[i];
    dp[0][0][0]=0;

    rep(i,0,n){
        rep(j,0,k+1){
            for(auto itr=dp[i][j].begin();itr!=dp[i][j].end();itr++){
                ll add=max(h[i]-(*itr).fs,0ll);

                if(!dp[i+1][j+1].count((*itr).fs))dp[i+1][j+1][(*itr).fs]=dp[i][j][(*itr).fs];
                else chmin(dp[i+1][j+1][(*itr).fs],dp[i][j][(*itr).fs]);
                
                if(!dp[i+1][j].count(h[i]))dp[i+1][j][h[i]]=dp[i][j][(*itr).fs]+add;
                else chmin(dp[i+1][j][h[i]],dp[i][j][(*itr).fs]+add);
            }
        }
    }

    ll ans=LINF;
    for(auto itr=dp[n][k].begin();itr!=dp[n][k].end();itr++){
        ans=min(ans,(*itr).sc);
    }
    cout<<ans<<endl;
}


//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,output_format?