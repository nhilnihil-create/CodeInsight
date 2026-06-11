#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const long long INF = 1LL << 60;


int solve(ll l, ll r) {
  
  int v = 2019;
  
  for (ll i = l; i <= r; ++i) {
    for (ll j = i+1; j <= r; ++j) {
      int mod = (i*j)%2019;
      v = min(v, mod);
    }
  }
  return v;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll l,r; cin>>l>>r;
  
  int res = 0;
  
  if(r-l+1>=2019) res = 0;
  else {
    res = solve(l, r);
  }
  
  cout<<res;
  
  return 0;
}