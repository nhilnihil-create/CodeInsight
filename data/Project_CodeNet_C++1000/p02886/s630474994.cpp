#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;

void solve() {
  cin >> n;
  int d[n];
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  ll ans = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      ans += d[i]*d[j];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
