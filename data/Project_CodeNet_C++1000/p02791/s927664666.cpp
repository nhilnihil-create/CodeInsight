#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int cnt = 0;
  int cmin = 1e9;
  rep(i, n) {
    if(cmin > p[i]) {
      cmin = p[i];
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}