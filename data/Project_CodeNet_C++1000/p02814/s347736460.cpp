#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,ll> P;
typedef tuple<int,int,int> TP;
constexpr int INF = 2e9;
ll gcd(ll a, ll b){
    if(b == 0)return a;
    return gcd(b,a%b);
}

ll lcm(ll c, ll d){
    ll g = gcd(c,d);
    ll l = c/g*d;//最小公倍数
    return l;
}
int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) cin >> a[i], a[i] /= 2;

  set<int> st;
  auto calc = [&](ll x){
    int cnt = 0;
    while (x % 2 == 0) {
      x /= 2;
      cnt++;
    }
    st.insert(cnt);
    return (int)st.size() == 1;
  };
  int ok = 1;
  for (int i = 0; i < n; i++) {
    ok &= calc(a[i]);
  }
  if (!ok) {
    cout << 0 << endl;
    return 0;
  }
  ll lc = 1;
  for (int i = 0; i < n; i++) {
    lc = lcm(lc, a[i]);
    if (lc > m) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << (m / lc + 1) / 2 << endl;
  return 0;
} 