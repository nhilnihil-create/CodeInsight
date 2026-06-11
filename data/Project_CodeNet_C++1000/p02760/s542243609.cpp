#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;


int main() {
  vector<vector<int>> a(3, vector<int>(3));
  rep(i,3)rep(j,3) {
    cin >> a[i][j];
  }
  int n;
  cin >> n;
  vector<bool> t(101, false);
  rep(i,n) {
    int b;
    cin >> b;
    t[b] = true;
  }
  rep(i,3) {
    if (t[a[i][0]] && t[a[i][1]] && t[a[i][2]]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  rep(i,3) {
    if (t[a[0][i]] && t[a[1][i]] && t[a[2][i]]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (t[a[0][0]] && t[a[1][1]] && t[a[2][2]]) {
    cout << "Yes" << endl;
    return 0;
  }
  if (t[a[0][2]] && t[a[1][1]] && t[a[2][0]]) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}