#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n, d;
  cin >> n >> d;
  
  vector<vector<int>> x(n, vector<int>(d));
  REP(i,n) {
    REP(j,d) {
      cin >> x[i][j];
    }
  }
  
  int ans = 0;
  int y = 0, z = 0;
  REP(i,n-1) {
    for(int j = i+1; j < n; j++) {
      REP(k,d) {
        y += pow((x[i][k] - x[j][k]),2);
      }
      z = pow(y,0.5);
      if (z * z == y) ans++;
      y = 0;
    }
  }    
  
  cout << ans << endl;
  
}