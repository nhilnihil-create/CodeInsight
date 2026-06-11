#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> vec(n);
  rep(i,n) {
    int a;
    cin >> a;
    rep(j, a) {
      int x,y;
      cin >> x >> y;
      vec[i].push_back(make_pair(x-1, y));
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    vector<bool> r(n, false);
    for (int j = 0; j < n; j++) {
      if(i >> j & 1) {
        r[j] = true;
      }
    }
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if(i >> j & 1) {
        for (auto p : vec[j]) {
          if (r[p.first] != p.second) {
            ok = false;
          }
        }
      }
    }
    
    if (!ok) continue;
    int cnt = 0;
    rep(j, n) {
      if (r[j]) cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}