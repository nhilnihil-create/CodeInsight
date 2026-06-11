#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  vector<ll> d(m), c(m);
  rep(i, m) cin >> d[i] >> c[i];
  ll sum = 0, digit = 0;
  rep(i, m) {
    sum += d[i]*c[i];
    digit += c[i];
  }
  ll ans = digit-1+(sum-1)/9;
  cout << ans << endl;
  return 0;
}