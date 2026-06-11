#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> cnt(n+1);
  for(int i = 1; i <= n; i++) {
    int j = 1;
    while(i*j <= n) {
      cnt[i*j]++;
      j++;
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += cnt[i] * i;
  }
  cout << ans << endl;
  return 0;
}