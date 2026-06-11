#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A[3][3];
  rep(i, 3) rep(j, 3) cin >> A[i][j];
  int N;
  cin >> N;
  bool bl[3][3];
  rep(i, 3) rep(j, 3) bl[i][j] = false;
  rep(i, N) {
    int B;
    cin >> B;
    rep(j, 3) {
      auto index = find(A[j], A[j]+3, B) - A[j];
      if (index<3) bl[j][index] = true;
    }
  }
  bool flag = false;
  rep(i, 3) {
    if (bl[i][0] == true && bl[i][1] && bl[i][2]) flag = true;
    if (bl[0][i] == true && bl[1][i] == true && bl[2][i] == true) flag = true;
  }
  if (bl[0][0] == true && bl[1][1] == true && bl[2][2] == true) flag = true;
  if (bl[0][2] == true && bl[1][1] == true && bl[2][0] == true) flag = true;
  if (flag) puts("Yes");
  else puts("No");
  return 0;
}