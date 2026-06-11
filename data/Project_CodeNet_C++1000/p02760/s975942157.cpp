#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  vector<vector<int>> a(3, vector<int>(3, 0));
  rep(i, 3){
    rep(j, 3) cin >> a[i][j];
  }
  int n;
  cin >> n;  
  int b;
  rep(i, n){
    cin >> b;
    rep(i, 3){
      rep(j, 3) {
        if(b == a[i][j]) a[i][j] = 0;
      }
    }
  }
  
  int ans = 0;
  if(a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0) ans =1;
  if(a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0) ans =1;
  if(a[2][0] == 0 && a[2][1] == 0 && a[2][2] == 0) ans =1;
  if(a[0][0] == 0 && a[1][0] == 0 && a[2][0] == 0) ans =1;
  if(a[0][1] == 0 && a[1][1] == 0 && a[2][1] == 0) ans =1;
  if(a[0][2] == 0 && a[1][2] == 0 && a[2][2] == 0) ans =1;
  if(a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) ans =1;
  if(a[2][0] == 0 && a[1][1] == 0 && a[0][2] == 0) ans =1;
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
return 0;
}