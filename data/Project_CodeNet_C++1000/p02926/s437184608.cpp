// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int y[100], x[100];

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n;
  cin >> n;
  
  vector<pair<double, int>> v;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    v.emplace_back(atan2(y[i], x[i]), i);
  }
  

  ll X = 0, Y = 0;
  ll ans = 0;

  auto check = [&]() {
    ans = max(ans, X * X + Y * Y);
  };

  auto now = [&]() {
    return (X * X + Y * Y);
  };

  auto add = [&](int i) {
    X += x[i];
    Y += y[i];
    check();
  };

  auto rem = [&](int i) {
    X -= x[i];
    Y -= y[i];
    check();
  };

  sort(begin(v), end(v));
  add(v.back().second);
  int r = 0;
  for(int i = 0; i < n; i++) {
    int j = (n + i - 1) % n;
    int id = v[i].second;
    rem(v[j].second);
    if(i == r) add(id), (++r) %= n;

    ll z = now();
    while(i != r) {
      int rid = v[r].second;
      add(rid);
      ll z2 = now();
      if(z > z2) {
        rem(rid);
        break;
      } else {
        (++r) %= n;
        z = z2;
      }
    }
  }
  cout << fixed << setprecision(11);
  cout << sqrt(ans) << endl;
  return 0;
}
