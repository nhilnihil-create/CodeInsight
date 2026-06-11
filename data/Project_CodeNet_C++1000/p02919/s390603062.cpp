#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
const int maxN = 2e5 + 10;

int n;
int p[maxN];

struct Tree{
  vector< pii > maxvt;
  vector< pii > minvt;
  int n;

  Tree(int _n = 0) : n(_n) {
    maxvt.resize(n * 4);
    fill(maxvt.begin(), maxvt.end(), mp(0, 0));

    minvt.resize(n * 4);
    fill(minvt.begin(), minvt.end(), mp(n+1, n+1));
  }

  pii getMax(pii L, pii R) {
    pair<int, int> ret;
    if (L.F == R.F) {
      return mp(L.F, R.F);
    }
    if (L.F < R.F) {
      ret.F = R.F;
      if (L.F > R.S) {
        ret.S = L.F;
      } else {
        ret.S = R.S;
      }
    } else {
      ret.F = L.F;
      if (R.F > L.S) {
        ret.S = R.F;
      } else {
        ret.S = L.S;
      }
    }
    return ret;
  }

  pii getMin(pii L, pii R) {
    pair<int, int> ret;
    if (L.F == R.F) {
      return mp(L.F, R.F);
    }
    if (L.F > R.F) {
      ret.F = R.F;
      if (L.F < R.S) {
        ret.S = L.F;
      } else {
        ret.S = R.S;
      }
    } else {
      ret.F = L.F;
      if (R.F < L.S) {
        ret.S = R.F;
      } else {
        ret.S = L.S;
      }
    }
    return ret;
  }

  void update(int u, int v, int id, int vt, int delta, int type) {
    if (u > vt || v < vt) return;

    if (u == vt && v == vt) {
      if (type == 0) {
        maxvt[id].F = delta;
      } else {
        minvt[id].F = delta;
      }
      return;
    }

    int mid = (u + v) / 2;
    update(u, mid, id * 2, vt, delta, type); update(mid + 1, v, id * 2 + 1, vt, delta, type);

    if (type == 0) {
      maxvt[id] = getMax(maxvt[id*2], maxvt[id*2+1]);
    } else {
      minvt[id] = getMin(minvt[id*2], minvt[id*2+1]);
    }
  }

  pii get(int u, int v, int id, int l, int r, int type) {
    if (u > r || v < l) {
      if (type == 0) return mp(0, 0);
      return mp(n+1,n+1);
    }
    if (l <= u && v <= r) {
      if (type == 0) return maxvt[id];
      return minvt[id];
    }
    int mid = (u + v) / 2;
    if (type == 0) {
      return getMax(get(u, mid, id * 2, l, r, 0) , get(mid + 1, v, id * 2 + 1, l, r, 0));
    }
    return getMin(get(u, mid, id * 2, l, r, 1) , get(mid + 1, v, id * 2 + 1, l, r, 1));
  }

};

pii l[maxN], r[maxN];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(NULL);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  Tree node(n);

  for (int i = 1; i <= n; ++i) {
    if (p[i] != n) l[i] = node.get(1, n, 1, p[i] + 1, n, 0);
    node.update(1, n, 1, p[i], i, 0);
  }

  for (int i = n; i > 0; --i) {
    if (p[i] != n) r[i] = node.get(1, n, 1, p[i] + 1, n, 1);
    node.update(1, n, 1, p[i], i, 1);
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (p[i] == n) continue;
    int lenL = i - l[i].F, lenR = r[i].F - i;
    int lenL2 = l[i].F - l[i].S, lenR2 = r[i].S - r[i].F;
    ans = ans + 1ll * p[i] * (1ll * lenL * lenR2 + 1ll * lenR * lenL2);
  }
  cout << ans;
return 0;
}
