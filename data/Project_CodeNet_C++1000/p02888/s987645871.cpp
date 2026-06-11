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
  int right = 2;
  rep(i, N) {
    right = i+2;
    for (int j = i+1; j < N; j++) {
      int ab = L[i] + L[j];
      while (right < N && L[right] < ab) right++;
      ans += max(0, right - (j+1));
    }
  }
  cout << ans << '\n'; 
  return 0;
}