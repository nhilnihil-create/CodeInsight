#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  vector<int> a = p;
  sort(a.begin(), a.end());
  int cnt = 0;
  rep(i, n) {
    if (a[i] != p[i]) cnt++;
  }
  if (cnt <= 2) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}