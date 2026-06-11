#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<double> v(n);
  rep(i, n) cin >> v[i];

  sort(v.begin(), v.end());
  double now = v[0];
  for (int i = 1; i < n; ++i) now = (now + v[i]) / 2;
  printf("%.6f\n", now);
  return 0;
}