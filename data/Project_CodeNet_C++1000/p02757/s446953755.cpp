#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int remain[200005];

int main() {
  // 素数が2,5に注意、ApplePen、余りの状態数を持ったdp
  // 余りの累積和を保持
  ll N, P;
  cin >> N >> P;
  string S;
  cin >> S;
  if (P == 2 || P == 5) {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
      int cur = S[i] - '0';
      if (cur%P == 0) ans += i+1;
    }
    cout << ans << '\n';
    return 0;
  }
  reverse(S.begin(), S.end());
  ll power = 1;
  ll temp = 0;
  remain[0] = 1;
  for (int i = 0; i < N; i++) {
    ll cur = S[i] - '0';
    temp += cur * power;
    temp %= P;
    remain[temp]++;
    power *= 10; power %= P;
  }
  ll ans = 0;
  for (int i = 0; i < P; i++) {
    ll r = remain[i];
    if (r > 1) ans += r * (r-1) / 2;
  }
  cout << ans << '\n';
  return 0;
}

// 20
