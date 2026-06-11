#include <bits/stdc++.h>
using namespace std;
#define ll long long

void ng() {
  puts("-1");
  exit(0);
}

int main() {
  int n;
  ll tot = 0, now = 1, ans = 0;
  cin >> n;
  vector<ll> d(n + 1);
  for (int i = 0; i <= n; i++) {
    cin >> d[i];
    tot += d[i];
  }
  for (int i = 0; i <= n; i++) {
    if (now < d[i]) ng();
    ans += now;
    now -= d[i];
    tot -= d[i];
    now = min(now * 2, tot);
  }
  cout << ans << endl;
}
