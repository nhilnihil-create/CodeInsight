#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector< vector<int> > v(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++){
    int u, k; cin >> u >> k;
    u--;
    for(int j = 0; j < k; j++){
      int a; cin >> a;
      a--;
      v[u][a] = 1;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j == n-1) cout << v[i][j];
      else cout << v[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}