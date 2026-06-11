#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, A[3][3], b[10];

int main(void){
  rep(i,3){
    rep(j,3){
      cin >> A[i][j];
    }
  }
  cin >> N;
  rep(i,N) cin >> b[i];

  bool appear[3][3];
  rep(i,3){
    rep(j,3){
      appear[i][j] = false;
      rep(k,N){
        if (A[i][j] == b[k]) appear[i][j] = true;
      }
    }
  }

  string ans = "No";
  rep(i,3){
    if (appear[i][0] && appear[i][1] && appear[i][2]) ans = "Yes";
    if (appear[0][i] && appear[1][i] && appear[2][i]) ans = "Yes";
  }
  if (appear[0][0] && appear[1][1] && appear[2][2]) ans = "Yes";
  if (appear[0][2] && appear[1][1] && appear[2][0]) ans = "Yes";

  cout << ans << endl;
}
