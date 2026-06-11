#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> d(10, vector<int>(10,0));
  rep(i,1,n+1) {
    if (i % 10 == 0) continue;
    int a = stoi(to_string(i).substr(0,1));
    int b = i % 10;
    d[a][b]++;
  }
  int ans = 0;
  rep(i,1,n+1) {
    if (i % 10 == 0) continue;
    int a = stoi(to_string(i).substr(0,1));
    int b = i % 10;
    ans += d[b][a];
  }
  cout << ans << endl;
  return 0;
}
