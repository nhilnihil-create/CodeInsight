#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll n, k;
  cin >> n >> k;
  vector<double> a(n);
  REP(i, n) cin >> a[i];
  sort(ALL(a));

  // r =  ok
  ll l = 0, r = a.back();
  while(r-l > 1){
    ll x = (l+r)/2;
    ll m = 0;
    REP(i, n) m += (a[i]+x-1)/x - 1;
    if(m <= k){
      r = x;
    }else{
      l = x;
    }
  }
  cout << r << endl;
  return 0;
}