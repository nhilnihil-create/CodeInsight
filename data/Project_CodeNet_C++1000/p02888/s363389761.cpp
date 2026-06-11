#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 二分探索
  int N;
  cin >> N;
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  sort(L.begin(), L.end());
  ll ans = 0;
  rep(i, N) for (int j = i+1; j < N; j++) {
    int index = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
    ans += index - 1 - j;
  }
  cout << ans << '\n'; 
  return 0;
}