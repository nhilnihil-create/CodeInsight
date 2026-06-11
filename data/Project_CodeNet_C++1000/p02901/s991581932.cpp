// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve(); int main() { solve(); return 0; }

void solve() {
  int n,m;cin >> n>>m;
  vector<pair<int,int>> K;
  loop(i,0,m) {
    int a, b, c;
    cin >> a >> b;
    int S = 0;
    loop(j,0,b) {
      cin >> c; c--;
      S |= 1<<c;
    }
    K.emplace_back(S, a);
  }
  
  const int INF = 1001001001;
  vector<int> dp(1<<n, INF);
  dp[0] = 0;
  for (int S=0; S<1<<n; S++) {
    for (auto&&k: K) {
      int T = S|k.first;
      dp[T] = min(dp[T], dp[S] + k.second);
    }
  }
  
  int ans = dp.back();
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}
