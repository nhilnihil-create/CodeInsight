#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<vector<int>> direction(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    direction[a-1].push_back(b-1);
    direction[b-1].push_back(a-1);
  }
  int cnt = 0;
  rep(i, n) {
    bool flag = true;
    rep(j, direction[i].size()) {
      if(h[i] <=h[direction[i][j]]) flag = false;
    }
    if(flag) cnt++;
  }
  cout << cnt << endl;
  return 0;
}