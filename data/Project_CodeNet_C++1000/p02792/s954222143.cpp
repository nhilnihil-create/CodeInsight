#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); ++i)
#define repj(n) for (long long j = 0; j < (n); ++j)
#define repk(n) for (long long k = 0; k < (n); ++k)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

ll sc[10][10];
int main() {
  auto msd = [](const int& x) {
    int y = x;
    while (y >= 10) y /= 10;
    return y;
  };
  int n;
  cin >> n;
  rep(i, 1, n + 1) sc[msd(i)][i % 10]++;
  ll res = 0;
  rep(i, 1, 10) rep(j, 1, 10) res += sc[i][j] * sc[j][i];
  cout << res << endl;
}
