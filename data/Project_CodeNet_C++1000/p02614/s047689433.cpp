#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m, k, black = 0; cin >> n >> m >> k;
  vector <string> grid(n);
  for(int i = 0; i < n; i++) cin >> grid[i];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (grid[i][j] == '#') black++;
    }
  }
  
  int temp = 0; 
  long long ans = 0;
  for(int i = 0; i < (1 << n); i++) {
    for(int j = 0; j < (1 << m); j++) {
      temp = 0;
      for(int k = 0; k < n; k++) {
        if (((1 << k) & i) == 0) continue;
        for(int l = 0; l < m; l++) {
          if (((1 << l) & j) == 0) continue;
          if (grid[k][l] == '#') temp++;
        }
      }
      if (temp == k) ans++;
    }
  }
  cout << ans;
}