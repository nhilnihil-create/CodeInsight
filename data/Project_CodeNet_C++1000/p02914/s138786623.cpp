#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repr(i, n) for (ll i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;

const int MAX_ROW = 110;
const int MAX_COL = 110000;
struct BitMatrix {
  int H, W;
  bitset<MAX_COL> val[MAX_ROW];
  BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
  inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};

void GaussJordan(BitMatrix &A, bool is_extended = false) {
  vector<bool> used(A.H, 0);
  for (int col = 0; col < A.W; ++col) {
    if (is_extended && col == A.W - 1) break;
    int pivot = -1;
    for (int row = 0; row < A.H; ++row) {
      if (used[row]) continue;
      if (A[row][col]) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) continue;
    for (int row = 0; row < A.H; ++row) {
      if (row != pivot && A[row][col]) A[row] ^= A[pivot];
    }
    used[pivot] = true;
  }
}

const int MD = 60;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll res = 0;
  BitMatrix B(MD + 1, n + 1);
  vector<bool> cannot(MD + 1, 0);
  repr(d, MD) {
    ll num = 0;
    rep(i, n) {
      if (a[i] & (1LL << d)) num++;
    }
    if (num == 0) {
      cannot[d] = 1;
      continue;
    }
    else if (num & 1) {
      cannot[d] = 1;
      res += (1LL << d);
      continue;
    }
    rep(i, n) {
      if (a[i] & (1LL << d)) B[MD - d][i] = 1;
    }
    B[MD - d][n] = 1;
  }
  GaussJordan(B, true);

  repr(d, MD) {
    if (cannot[d]) continue;
    bool ok = false;
    rep(i, n) {
      if (B[MD - d][i]) ok = true;
    }
    if (!B[MD - d][n]) ok = true;
    if (ok) res += (2LL << d);
  }
  cout << res << endl;


}