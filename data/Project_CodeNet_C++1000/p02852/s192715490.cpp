#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; string s;
  cin >> n >> m >> s;
  vector<int> line(n+1);
  rep(i,0,n+1) {
    line[i] = stoi(s.substr(n-i,1));
  }
  int p = 0;
  vector<int> ans;
  bool flag = false;
  while (p < n) {
    int j = min(n,p+m);
    while (j > p) {
      if (line[j] == 0) {
        break;
      }
      j--;
    }
    if (j == p) {
      flag = true;
      break;
    }
    ans.push_back(j-p);
    p = j;
  }
  int l = ans.size();
  if (flag) {
    cout << -1 << endl;
  } else {
    rep(i,0,l-1) {
      cout << ans[l-i-1] << " ";
    }
    cout << ans[0] << endl;
  }
  return 0;
}
