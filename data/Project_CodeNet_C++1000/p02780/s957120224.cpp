#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> p(n);
  rep(i, n) cin >>  p[i];
  
  rep(i, n) p[i] = (1 + p[i]) / 2;
  double sum = 0;
  rep(i, k) sum += p[i];
  double ans = sum;
  for (int i = 1; i + k - 1 < n; ++i) {
    sum = sum - p[i-1] + p[i + k - 1];
    ans = max(ans, sum);
  }
  printf("%.1f\n", ans);
  return 0;
}