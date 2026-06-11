#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

int N;
double x[20], y[20];

int main() {
  int perm[8];

  cin >> N;

  rep(i, 0, N) { perm[i] = i; }
  rep(i, 0, N) { cin >> x[i] >> y[i]; }

  vector<double> dists;
  do {
    rep(i, 0, N - 1) {
      int ci = perm[i];
      int ni = perm[i + 1];

      double cx = x[ci];
      double nx = x[ni];
      double dx = cx - nx;
      double cy = y[ci];
      double ny = y[ni];
      double dy = cy - ny;

      dists.push_back(sqrt(dx * dx + dy * dy));
    }
  } while (next_permutation(perm, perm + N));

  double sum = 0.0;
  sort(dists.begin(), dists.end());
  for (auto e : dists) {
    sum += e;
  }

  ll patterns = 1;
  repe(i, 1, N) { patterns *= i; }

  cout << setprecision(20) << fixed << sum / patterns << endl;
}
