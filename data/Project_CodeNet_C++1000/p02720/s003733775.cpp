#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;
  cin >> k;
  vector<ll> ans(100005, 0);
  queue<ll> q;
  rep(i, 1, 10) {
    ans[i] = i;
    q.push(i);
  }

  int cur = 10;
  while (cur < 100001) {
    ll t = q.front();
    q.pop();
    string ts = to_string(t);
    ts += ts[ts.size() - 1];
    ll x = stol(ts);

    if (t % 10 == 0) {
      ans[cur++] = x;
      ans[cur++] = x + 1;
      q.push(x);
      q.push(x + 1);
    } else if (t % 10 == 9) {
      ans[cur++] = x - 1;
      ans[cur++] = x;
      q.push(x - 1);
      q.push(x);
    } else {
      ans[cur++] = x - 1;
      ans[cur++] = x;
      ans[cur++] = x + 1;
      q.push(x - 1);
      q.push(x);
      q.push(x + 1);
    }
  }

  cout << ans[k] << endl;
}
