#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<vector<pair<int,int>>> a(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    for (int j = 0; j < num; j++) {
      int x,y;
      cin >> x >> y;
      x--;

      a[i].emplace_back(x,y);
    }
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++) {
    bool ok = true;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if(1 & (bit >> (n - 1 - i))) { // honest
        cnt++;
        for (auto it: a[i]) {
          int itr = it.first;
          int b = it.second;
          if((1 & (bit >> (n - 1 - itr))) != b) {
            ok = false;
            break;
          }
        }
      }
      if(!ok) break;
    }
    if(ok) {
      ans = max(ans, cnt);
      //cout << bit << '\n';
    }
  }
  cout << ans << '\n';
}
