#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> num(m);
  rep(i, m) cin >> num[i].first >> num[i].second;
  rep(i, 1000) {
    int keta = 1;
    int x = i/10;
    vector<int> d(1, i%10);
    while(x) {
      keta++;
      d.push_back(x%10);
      x /= 10;
    }
    if(keta != n) continue;
    reverse(d.begin(), d.end());
    bool flag = true;
    rep(i, m) {
      if(d[num[i].first-1] != num[i].second) flag = false;
    }
    if(flag) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}