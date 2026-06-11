#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  int ans = 0;
  rep(i, N) {
    if (H[i] >= K) ans++;
  }
  cout << ans << '\n';  
  
  return 0;
}