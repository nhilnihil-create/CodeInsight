#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), inv(n + 1);
  REP(i, n) {
    cin >> a[i];
    inv[a[i]] = i + 1;
  }
  multiset<ll> st;
  REP(_, 2) {
    st.insert(0);
    st.insert(n + 1);
  }
  ll ans = 0;
  IFOR(x, 1, n + 1) {
    ll c = inv[x];
    st.insert(c);
    auto it = st.lower_bound(c);
    ll u1 = *(++it);
    ll u2 = *(++it);
    it--;
    it--;
    ll l1 = *(--it);
    ll l2 = *(--it);

    ll d = (u1 - c) * (l1 - l2) + (u2 - u1) * (c - l1);

    ans += x * d;
  }
  cout << ans << endl;
}