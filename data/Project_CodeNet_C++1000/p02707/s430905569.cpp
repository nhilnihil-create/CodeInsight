#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> boss(n);
  rep(i, n) {
    if(i == 0) continue;
    int a;
    cin >> a;
    boss[a-1].push_back(i-1);
  }
  rep(i, n) cout << boss[i].size() << endl;
  return 0;
}
    