#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

ll ndat;
vector<ll> dat;

void rmg_init(ll n_) {
  ndat = 1;
  while (ndat < n_) ndat *= 2;
  dat.resize(2 * ndat - 1, INF);
}

void update(ll k, ll a) {
  k += ndat - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

ll query(ll a, ll b, ll k, ll l, ll r) {
  if (r <= a || b <= l) return INF;
  if (a <= l && r <= b) return dat[k];
  else {
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}

int main() {
  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  rmg_init(n + 1);
  update(0, 0);
  reverse(s.begin(), s.end());
  FOR(i, 1, n + 1) {
    if (s[i] == '1') continue;
    ll cnt = query(i - m, i, 0, 0, ndat);
    if (cnt != INF) {
      update(i, cnt + 1);
    }
  }
  if (dat[ndat + n - 1] == INF) {
    cout << -1 << endl;
    return 0;
  }
  else {
    map<ll, ll> idx;
    rep(i, n + 1) {
      idx[dat[i + ndat - 1]] = i;
    }
    repr(i, dat[ndat + n - 1] - 1) {
      cout << idx[i + 1] - idx[i] << " ";
    }
    cout << endl;
  }

  


  
  return 0;
}