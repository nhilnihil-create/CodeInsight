#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a;}

int main() {
  // Brute
  int K;
  cin >> K;
  ll ans = 0;
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= K; j++) {
      int x = gcd(i, j);
      for (int k = 1; k <= K; k++) {
        ans += gcd(x, k);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}