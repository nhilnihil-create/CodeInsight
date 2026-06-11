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
#include <limits>
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

ll d[60];

int main() {
  ll n;
  cin>>n;
  vector<ll> v;
  rep(i,0,n){
    ll a;
    cin>>a;
    v.pb(a);
  }
  rep(i,0,v.sz){
    rep(j,0,60){
      if((v[i]>>j)&1LL){
        d[j]++;
      }
    }
  }
  ll ans1 = 0;
  rep(i,0,60){
    if(d[i]%2==1){
      ans1 += 1LL<<i;
      ll mask = (1LL<<60)-1LL;
      mask ^= (1LL<<i);
      rep(j,0,v.sz){
        v[j] &= mask;
      }
    }
  }
  ll sum = 0;
  rep(i,0,v.sz){
    sum ^= v[i];
  }
  ll index = 0;
  per(i,0,60){
    ll flag = 0;
    rep(j,index,v.sz){
      if(v[j]&(1LL<<i)){
        flag = 1;
        swap(v[index],v[j]);
        break;
      }
    }
    rep(j,index+1,v.sz){
      if(v[j]&(1LL<<i)){
        v[j]^=v[index];
      }
    }
    if(flag==1){
      index++;
    }
  }
  ll mx = 0;
  rep(i,0,v.sz){
    ll a = mx^v[i];
    if(a>mx)mx^=v[i];
  }
  cout << (ans1 + mx + (mx^sum)) << endl;
  return 0;
}