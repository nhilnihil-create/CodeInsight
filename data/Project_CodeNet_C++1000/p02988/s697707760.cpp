#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  rep(i, N) cin >> P[i];
  int ans = 0;
  for (int i = 1; i < N-1; i++) {
    if ((P[i] != max({P[i-1], P[i], P[i+1]})) && (P[i] != min({P[i-1], P[i], P[i+1]}))) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}