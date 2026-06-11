#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

ll mod(ll a) {
  return (a % 2019);
}

void solve() {
  ll l, r;
  cin >> l >> r;
  ll x = r - l;
  ll ans = 2020;
  if (x >= 2019) ans = 0;
  else {
    if (mod(l) > mod(r)) ans = 0;
    else {
      for (ll i = mod(l); i <= mod(r); i++) {
        for (ll j = i+1; j <= mod(r); j++) {
          ans = min(ans, mod(i*j));
        }
      }
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}