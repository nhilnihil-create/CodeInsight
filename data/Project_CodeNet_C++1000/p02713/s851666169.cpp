#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int K;
  cin >> K;
  K++;
  int cnt = 0;
  rep(a, K) rep(b, K) rep(c, K) {
    if (a == 0 || b == 0 || c == 0) continue;
    cnt += gcd(gcd(a, b), c);
  }
  cout << cnt << endl;
}
