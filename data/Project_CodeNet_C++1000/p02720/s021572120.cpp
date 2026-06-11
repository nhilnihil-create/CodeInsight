#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int k;
  cin >> k;
  queue<ll> q;
  rep(i, 9) q.push(i + 1);

  ll ans;
  rep(i, k) {
    ans = q.front();
    q.pop();
    if(ans % 10 != 0)
      q.push(10 * ans + ans % 10 - 1);
    q.push(10 * ans + ans % 10);
    if(ans % 10 != 9)
      q.push(10 * ans + ans % 10 + 1);
  }
  cout << ans;
}
