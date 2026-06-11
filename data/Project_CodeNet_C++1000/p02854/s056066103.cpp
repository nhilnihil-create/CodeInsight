//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  ll n, sum = 0;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  ll cnt = 1e10, sub = 0;
  rep(i, n) {
    sub += a[i];
    cnt = min(cnt, abs(sum-2*sub));
  }
  cout << cnt << endl;
  return 0;
}