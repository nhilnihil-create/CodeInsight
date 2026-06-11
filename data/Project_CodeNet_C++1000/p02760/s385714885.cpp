#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

const int N = 3;
int bingo[N][N];
int a[N][N];

signed main() {
  rep(i,N) rep(j,N) cin >> a[i][j];
  int n;
  cin >> n;
  rep(i,n) {
    int x; cin >> x;
    rep(j,N) {
      rep(k,N) {
        if(a[j][k] == x) bingo[j][k] = 1;
      }
    }
  }
  bool ok = false;
  rep(i,N) {
    if(bingo[i][0] && bingo[i][1] && bingo[i][2]) ok = true;
  }
  rep(i,N) {
    if(bingo[0][i] && bingo[1][i] && bingo[2][i]) ok = true;
  }
  if(bingo[0][0] && bingo[1][1] && bingo[2][2]) ok = true;
  if(bingo[2][0] && bingo[1][1] && bingo[0][2]) ok = true;

  if(ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}