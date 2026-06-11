#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  string S;
  cin >> N >> S;
  ll r, g, b;
  r = g = b = 0;
  rep(i, N) {
    if (S.at(i) == 'R') r++;
    if (S.at(i) == 'G') g++;
    if (S.at(i) == 'B') b++;
  }
  ll cnt = r * g * b;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int k = 2 * j - i;
      if (k >= N) continue;
      if (S.at(i) != S.at(j) && S.at(j) != S.at(k) && S.at(k) != S.at(i)) cnt--;
    }
  }
  cout << cnt << endl;
}
