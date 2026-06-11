#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x,n;
  cin >> x >> n;
  vector<int> p(n);
  rep(i,n) {
    cin >> p[i];
  }
  vector<int> line;
  rep(i,n * 4) {
    line.push_back(x - 2 * n + i);
  }

  int ans = 101;
  if(line.size() == 0) {
    cout << x << endl;
    return 0;
  }
  for(int a : line) {
    bool isContained = false;
    int dif = abs(x - abs(a));
    rep(i, n) {
      if(a == p[i]) isContained = true;
    }
    // cout << ans << " " << a << " " << dif << " " << isContained << endl;
    if(abs(x - ans) > dif && !isContained) {
      ans = a;
    }else if(abs(x - ans) == dif && !isContained) ans = min(ans,a);
  }
  cout << ans << endl;
  return 0;
}
