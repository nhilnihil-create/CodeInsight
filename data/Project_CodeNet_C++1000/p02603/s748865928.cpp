#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll c = 1000, s = 0;
  rep(i, n-1) {
    if (a[i] < a[i+1]) {
      s += c / a[i];
      c %= a[i];
    }
    if (a[i] > a[i+1]) {
      c += s * a[i];
      s = 0;
    }
  }
  c += s * a[n-1];
  cout << c << endl;
  return 0;
}