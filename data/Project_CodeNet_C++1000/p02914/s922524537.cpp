#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int GaussJordanElim(vector<ll>& a, vector<int>& col) {
    int rank = 0, n = a.size();
    for (int i = 60; i >= 0; --i) {
        int j = rank;
        for (; j < n; ++j) {
            if (a[j]>>i&1) {
                swap(a[rank], a[j]);
                break;
            }
        }
        if (j == n) continue;
        col[rank] = i;
        rep(k,n) {
            if (rank == k) continue;
            if (a[k]>>i&1) a[k] ^= a[rank];
        }
        ++rank;
    }
    return rank;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll s = 0;
  rep(i,n) s ^= a[i];
  ll ans = s;
  rep(i,n) a[i] &= ~s;
  vector<int> col(n);
  int r = GaussJordanElim(a, col);
  ll x = 0;
  for (int i = 60; i >= 0; --i) {
    ll nx = x | (1ll<<i);
    {
      ll b = nx;
      rep(j,r) {
        if (b>>col[j]&1) b ^= a[j];
      }
      if ((b & nx) == 0) x = nx;
    }
  }
  ans += x*2;
  cout << ans << endl;
  return 0;  
}