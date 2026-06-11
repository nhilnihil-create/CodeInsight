#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; i++)
#include <bits/stdc++.h>
using namespace std;
//~ using ll = long long;
//~ using P = pair<int, int>;

int main(){
  vector<vector<int>> a(3, vector<int>(3));
  vector<vector<int>> r(3, vector<int>(3, 0));
  rep(i, 3) rep(j, 3) cin>> a[i][j];
  
  int n;
  cin >> n;
  
  int b;
  rep(i, n){
    cin >> b;
    rep(j, 3) rep(k, 3) if(a[j][k]==b) r[j][k]=1;
  }
  
  rep(i, 3) {
    if((r[i][0] && r[i][1] && r[i][2]) ||
       (r[0][i] && r[1][i] && r[2][i]) ||
       (r[0][0] && r[1][1] && r[2][2]) ||
       (r[0][2] && r[1][1] && r[2][0])){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  
  return 0;
}
