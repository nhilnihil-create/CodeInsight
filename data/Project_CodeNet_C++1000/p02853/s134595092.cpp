#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()
#define all(arr) arr.begin(), arr.end()

using namespace std;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

int main() {
  map<int, int> mp;
  mp[3] = 100000;
  mp[2] = 200000;
  mp[1] = 300000;

  Cin(int, x, y);
  int ans = mp[x] + mp[y];
  if (x == 1 && y == 1) ans += 400000;

  cout << ans << endl;

  return 0;
}