#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int a[3][3], b[10];
  bool result[3][3];
  
  rep(i,3)rep(j,3) cin >> a[i][j];
  
  int n;
  cin >> n;
  
  rep(i,n) cin >> b[i];
  rep(i,n)rep(j,n){
    result[i][j] = false;
    rep(k,n)if(a[i][j] == b[k]) result[i][j] = true;
  }
  
  string ans="No";
  rep(i,3)if(result[i][0] && result[i][1] && result[i][2]) ans = "Yes";
  rep(i,3)if(result[0][i] && result[1][i] && result[2][i]) ans = "Yes";
  if(result[0][0] && result[1][1] && result[2][2]) ans = "Yes";
  if(result[0][2] && result[1][1] && result[2][0]) ans = "Yes";
  cout << ans << endl;
  return 0;
}
