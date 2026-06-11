#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), l(n);
  rep(i, n) cin >> x[i] >> l[i];

  vector<P> rl(n);
  rep(i, n) rl[i] = make_pair(x[i] + l[i], x[i] - l[i]);
  sort(rl.begin(), rl.end());

  int num_bot = 0;
  int r = -1e9;
  rep(i, n) {
    if (rl[i].second < r) continue;
    r = rl[i].first;
    ++num_bot;
  }
  cout << num_bot << endl;
  return 0;
}