#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(ll i=(ll)(b-1);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

ll n,m,v,p;
vector<ll>a;
bool check(ll ii){
  if(a[ii]+m<a[n-p])return 0;
  if(v<=p&&a[ii]+m>=a[n-p]){
    return 1;
  }
  ll vv=v-p;
  ll S=0;
  rep(i,n-p+1){
    if(i==ii)continue;
    S+=min(m,m+a[ii]-a[i]);
  }
  return S>=m*vv;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>v>>p;
  a.resize(n);
  rep(i,n)cin>>a[i];
  ll ng=-1,ok=n;
  sort(all(a));
  while(ok-ng>1){
    ll mi=(ok+ng)/2;
    if(check(mi))ok=mi;
    else ng=mi;
  }
  cout<<n-ok<<endl;



  return 0;

}
