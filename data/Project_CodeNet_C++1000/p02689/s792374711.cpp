//グラフ

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, M;
  cin >> N >> M;
  vector <int> H(N);
  vector <bool> ok(N, true);
  rep(i,N) cin >> H[i];
  rep(i,M){
    int a, b;
    cin >> a >> b;
    a--; b--;  //0-indexedに直す
    if (H[a] <= H[b]) ok[a] = false;
    if (H[b] <= H[a]) ok[b] = false;
  }
  int ans = 0;
  rep(i,N) if (ok[i]) ans ++;
  cout << ans << endl;
  return 0;
}
