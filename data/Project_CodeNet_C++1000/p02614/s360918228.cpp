#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define erep(i, n) for(ll i = 1; i <= (n); i++)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> c(h);
  rep(i, h) cin >> c[i];
  int ans = 0;
  rep(i, 1<<h)rep(j,1<<w){
    int cnt = 0;
    rep(k, h)rep(l, w){
      if(i>>k&1) continue;
      if(j>>l&1) continue;
      if(c[k][l] == '#')cnt++;
    }
    if(cnt == k)ans++;
  }
  cout << ans << '\n';
  return 0;
}