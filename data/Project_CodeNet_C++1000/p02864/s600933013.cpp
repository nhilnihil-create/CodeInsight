#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;
 
#define INF 1000000007

ll dp[310][310][310];

int main(){
  ll n,K;
  cin>>n>>K;
  rep(i,0,310)rep(j,0,310)rep(k,0,310)dp[i][j][k] = 1000000000000000000LL;
  vector<ll> v;
  vector<ll> v1;
  v.pb(0);
  v1.pb(0);
  rep(i,0,n){
    ll a;
    cin>>a;
    v.pb(a);
    v1.pb(a);
  }
  sort(all(v1));
  map<ll,ll> ma;
  rep(i,0,v1.sz){
    ma[v1[i]] = i;
  }
  dp[0][0][0] = 0;
  rep(i,1,v.sz){
    ll h2 = v[i];
    rep(j,0,v1.sz){
      ll h1 = v1[j];
      rep(k,0,305){
        // use
        dp[i][ma[h2]][k] = min(dp[i][ma[h2]][k],dp[i-1][j][k]+max(0LL,h2-h1));
        // no use
        dp[i][ma[h1]][k+1] = min(dp[i][ma[h1]][k+1],dp[i-1][j][k]);
      }
    }
  }
  ll mn = 1000000000000000000LL;
  rep(i,0,310){
    rep(j,0,310){
      if(j<=K)mn = min(mn,dp[v.sz-1][i][j]);
    }
  }
  cout << mn << endl;
  return 0;
}