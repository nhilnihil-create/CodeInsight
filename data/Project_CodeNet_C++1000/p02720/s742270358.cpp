#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 全部入れてからsort
  int K;
  cin >> K;
  queue<ll> que;
  for (int i = 1; i < 10; i++) {
    que.push(i);
  }
  rep(i, K-1) {
    ll x = que.front(); que.pop();
    int first = x % 10;
    if (first >= 1) que.push(x*10 + first - 1);
    que.push(x*10 + first);
    if (first <= 8) que.push(x*10 + first + 1);
  }
  ll ans = que.front();
  cout << ans << '\n';
  return 0;
}