#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll r = 0;
  for (ll i = 0; i < N; i++) {
    if (S[i] == 'R') r++;
  }
  ll ans = 0;
  for (ll i = 0; i < r; i++) {
    if (S[i] != 'R') ans++;
  }
  cout << ans << endl;
}
