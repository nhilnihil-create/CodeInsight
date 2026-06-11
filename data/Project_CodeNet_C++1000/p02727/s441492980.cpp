#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> red, green, plain;
  rep(i, a) {
    int t; cin >> t;
    red.push_back(t);
  }
  rep(i, b) {
    int t; cin >> t;
    green.push_back(t);
  }
  rep(i, c) {
    int t; cin >> t;
    plain.push_back(t);
  }

  sort(red.begin(), red.end(), greater<int>());
  sort(green.begin(), green.end(), greater<int>());
  sort(plain.begin(), plain.end());

  vector<int> apples(a + b + c);
  copy(red.begin(), red.begin() + x, apples.begin());
  copy(green.begin(), green.begin() + y, back_inserter(apples));
  copy(plain.begin(), plain.end(), back_inserter(apples));
  sort(apples.begin(), apples.end(), greater<int>());
  
  ll ans = 0;
  rep(i, x + y) {
    ans += apples[i];
  }
  cout << ans;
}
