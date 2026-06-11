#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  int ans = 1;
  int cur = 0;
  for (int i = 0; i < N; i++) {
    cur += L[i];
    if (cur <= X) {
      ans++;
    } else break;
  }
  cout << ans << '\n';
  return 0;
}