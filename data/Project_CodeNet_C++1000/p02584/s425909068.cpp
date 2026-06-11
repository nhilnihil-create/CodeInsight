#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x, k, d;
void input() { cin >> x >> k >> d; }

void solve() {
  long long ans;
  x = abs(x);
  if (x / d >= k) {
    ans = abs(x - d * k);
  } else {
    ll s = x / d;  //周期に入るまでの回数
    k -= s;
    x -= s * d;
    if (k & 1) x = abs(x - d);  //奇数なら0を跨ぎ
    ans = x;                    //偶数ならそのまま
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
  getchar();
}