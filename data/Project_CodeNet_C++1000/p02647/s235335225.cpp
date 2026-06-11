#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  while (k--) {
    vector<ll> b(n + 1);
    rep(i, n) b[max(0LL, i - a[i])]++, b[min(i + a[i] + 1, n)]--;
    rep(i, n ) b[i + 1] += b[i];
    b.pop_back();
    if (a == b) break;
    a = b;
  }
  rep(i,n) cout << a[i] << ' ';
}