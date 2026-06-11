#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
// typedef pair<ll, ll> P;
typedef pair<double, double> P;
typedef pair<double, P> DP;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  double x[n], y[n];
  REP(i, n) cin >> x[i] >> y[i];
  vector<DP> vec;
  REP(i, n) {
    vec.push_back(make_pair(atan2(y[i], x[i]), make_pair(x[i], y[i])));
  }
  sort(ALL(vec));
  REP(i, n) vec.push_back(vec[i]);
  double ans = 0;
  REP(i, n) for (int j = i; j < n + i; ++j) {
    double nx = 0, ny = 0;
    for (int k = i; k <= j; ++k) {
      nx += vec[k].second.first;
      ny += vec[k].second.second;
    }
    ans = max(ans, nx * nx + ny * ny);
  }
  printf("%.50f\n", sqrt(ans));
  return 0;
}