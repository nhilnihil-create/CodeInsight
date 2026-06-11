#include <iostream>
#include <limits>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"
const int INF = numeric_limits<int>::max();

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; in(N);

  int x[N], y[N];
  rep(i, N) {
    in(x[i]); in(y[i]);
  }

  if (N == 1) {
    out(1);
    return 0;
  }
  int ans = INF;
  rep(i, N) rep(j, N) {
    if (i == j)
      continue;
    int p = x[i] - x[j];
    int q = y[i] - y[j];
    int tmp = 0;
    rep(k, N) rep(l, N) {
      if (k == l)
        continue;
      if (x[k] - x[l] == p && y[k] - y[l] == q)
        ++tmp;
    }
    ans = min(ans, N - tmp);
  }
  out(ans);

  return 0;
}
