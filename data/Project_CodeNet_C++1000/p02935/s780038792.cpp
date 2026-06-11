#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(v.rbegin(), v.rend());
  double cur = v[n-1];
  v.pop_back();
  while (!v.empty()) {
    cur += v.back();
    v.pop_back();
    cur /= 2.0;
  }
  printf("%.7f\n", cur);
  return 0;
}