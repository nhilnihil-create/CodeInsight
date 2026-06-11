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
 
#define MOD 1000000007

vector<ll> v;

ll f(ll n, ll x, ll m){
  ll ret = n-1;
  x %= m;
  vector<ll> v1;
  rep(i,0,v.sz){
    v1.pb(v[i]%m);
  }
  ll sum = 0;
  ll z = 0;
  rep(i,0,v1.sz){
    sum += v1[i];
    if(v1[i]==0)z++;
  }
  ll ans = 0;
  ll a = (n-1)/v1.sz;
  ll b = (n-1)%v1.sz;
  ll c = x+sum*a;
  ans += c/m;
  ans += z*a;
  c%=m;
  rep(i,0,b){
    if(v1[i]==0)ans++;
    c += v1[i];
    if(c>=m){
      ans++;
    }
    c%=m;
  }
  return ret-ans;
}

int main(){
  ll k,q;
  cin>>k>>q;
  rep(i,0,k){
    ll a;
    cin>>a;
    v.pb(a);
  }
  rep(i,0,q){
    ll n,x,m;
    cin>>n>>x>>m;
    ll ans = f(n,x,m);
    cout << ans << endl;
  }
  return 0;
}