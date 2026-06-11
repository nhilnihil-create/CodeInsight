#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define FI(i, a, b) for (int i = (a); i <= (b); ++i)
#define FD(i, a, b) for (int i = (b); i >= (a); --i)
#define DEBUG(x) cerr << #x << ": " << (x) << '\n';

const int N = 105;
int n;
pair<int, int> pv[N];

int main() {
  cin >> n;
  FI(i,1,n) scanf("%d%d", &pv[i].first, &pv[i].second);
  sort(pv + 1, pv + 1 + n, [](const pair<int, int> x, const pair<int, int> y) {
      return atan2(x.second, x.first) < atan2(y.second, y.first);
  });
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    LL sumx = 0, sumy = 0;
    for (int len = 0; len < n; ++len) {
      int j = (i + len - 1) % n + 1;
      sumx += pv[j].first, sumy += pv[j].second; 
      ans = max(ans, sqrt(sumx * sumx + sumy * sumy));
    }
  }
  printf("%.10f\n", ans);
}
