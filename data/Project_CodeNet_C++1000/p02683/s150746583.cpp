#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  
  vector<vector<int>> v(n, vector<int>(m+1));
  for(int i=0; i<n; i++) for(int j=0; j<m+1; j++) cin >> v[i][j];
  
  int ans = 10000000;
  vector<int> data(m, 0);
  for(int bit=0; bit<(1<<n); bit++) {
    int sum = 0;
    for(int i=0; i<n; i++) {
      if(bit & (1<<i)) {
        sum += v[i][0];
        for(int j=0; j<m; j++) {
          data[j] += v[i][j+1];
        }
      }  
    }
    
    bool check = true;
    for(int i=0; i<m; i++) if(data[i]<x) check = false;
    if(check && sum<ans) ans = sum;
    
    for(int i=0; i<m; i++) data[i] = 0;
  }
  
  if(ans==10000000) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}