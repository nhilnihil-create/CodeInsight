#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int graph[15][15];

int main() {
  int N;
  cin >> N;
  rep(i, N) rep(j, N) graph[i][j] = -1;
  rep(i, N) {
    int A;
    cin >> A;
    rep(j, A) {
      int x, y;
      cin >> x >> y;
      --x;
      graph[i][x] = y;
    } 
  }
  int ans = 0;  
  for (int bit = 0; bit < (1<<N); bit++) {
    //if (__builtin_popcount(bit) <= ans) continue;
    vector<int> temp(N);
    for (int i = 0; i < N; i++) {
      if ((bit>>i)&1) temp[i] = 1;
    }
    bool flag = true;
    rep(i, N) {
      if (temp[i] == 0) continue;
      rep(j, N) {
        if (graph[i][j] == -1) continue;
        if (graph[i][j] != temp[j]) {
          flag = false;
        }
      }
    }
    if (flag) ans = max(ans, __builtin_popcount(bit));
  }
  cout << ans << '\n';
  return 0;
}