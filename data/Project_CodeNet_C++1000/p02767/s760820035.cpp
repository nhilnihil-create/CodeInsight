#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

const int inf = 1000000000;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  int ans = inf;
  for (int i = 1; i <= 100; i++) {
    int cost = 0;
    rep(j,n) cost += (vec.at(j) - i) * (vec.at(j) - i);
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
