#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
using namespace std;

double sol(double a) {
  double res = 0.0;
  int q = a;
  while (q) {
    res += (q * (1 / a));
    --q;
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> p(n);
  vector<double> s(n + 1);
  rep (i, n) {
    int x;
    cin >> x;
    p[i] = sol(x);
  }

  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + p[i];
  }

  double ans = 1;
  for (int i = 0; i + k <= n; i++) {
    ans = max(ans, s[i + k] - s[i]);
  }

  cout << fixed << setprecision(15);
  cout << ans << endl;

  return 0;
}
