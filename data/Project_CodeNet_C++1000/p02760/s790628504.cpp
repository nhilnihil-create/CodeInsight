#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  vector<vector<int>> v(3, vector<int>(3)), c(3, vector<int>(3, -1));
  rep(i, 0, 3) {
    rep(j, 0, 3) {
      cin >> v[i][j];
    }
  }
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n) {
    rep(j, 0, 3) {
      rep(k, 0, 3) {
        if(v[j][k] == b[i]) {
          c[j][k] = 0;
        }
      }
    }
  }
  rep(i, 0, 3) {
    if(c[i][0] == 0 && c[i][1] ==  0 && c[i][2] == 0) {
      cout << "Yes\n";
      return 0;
    }
    if(c[0][i] == 0 && c[1][i] == 0 && c[2][i] == 0) {
      cout << "Yes\n";
      return 0;
    }
  }
  if(c[0][0] == 0 && c[1][1] == 0 && c[2][2] == 0) {
    cout << "Yes\n";
    return 0;
  }
  if(c[2][0] == 0 && c[1][1] == 0 && c[0][2] == 0) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}