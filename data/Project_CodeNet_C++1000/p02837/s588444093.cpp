#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<vector<pair<int, int>>> v(n);
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    for(int j = 0; j < a; j++) {
      int x, y;
      scanf("%d %d", &x, &y);
      v[i].push_back(make_pair(x - 1, y));
    }
  }
  
  int ans = 0;
  for (int tmp = 0; tmp < (1 << n); tmp++) {
    bitset<15> s(tmp);
    bool tsujitsuma = true;
    for(int i = 0; i < n; i++) {
      if(s.test(i)) {
        for(int j = 0; j < v[i].size(); j++) {
          if(v[i][j].second != s.test(v[i][j].first)) {
            tsujitsuma = false;
            break;
          }
        }
      }
      if(!tsujitsuma) break;
    }
    int cnt = s.count();
    if(tsujitsuma) ans = max(ans, cnt);
  }
  cout << ans;
}