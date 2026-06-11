#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x;
  scanf("%d %d %d", &n, &m, &x);
  vector<vector<int>> ca(n, vector<int>(m));//c[i][0]にはci
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= m; j++) cin >> ca[i][j];
  }
  int ans = 1300000;
  for (int tmp = 0; tmp < (1 << n); tmp++) {
    bitset<12> s(tmp);
    vector<int> xij(m + 1, 0);//xij[0]に合計金額
    for(int i = 0; i < n; i++) {
      if(s.test(i)) {
        for(int j = 0; j < m + 1; j++) {
          xij[j] += ca[i][j];
        }
      }
    }
    bool flag = true;
    for(int i = 1; i <= m; i++) {
      if(xij[i] < x) {
        flag = false;
        break;
      }
    }
    if(flag == true) ans = min(ans,xij[0]);
  }
  if(ans == 1300000) cout << -1;
  else cout << ans;
}