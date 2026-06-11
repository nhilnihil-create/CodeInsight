#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
int a[nax], b[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  queue<int> q;
  auto add = [&](int i) {
    int x = i ? b[i-1] : b[n-1];
    int y = b[i];
    int z = i+1 < n ? b[i+1] : b[0];
    if (y-x-z >= a[i]) {
      q.push(i);
    }
  };
  for (int i = 0; i < n; i++) {
    add(i);
  }
  ll ans = 0;
  while (q.size()) {
    int i = q.front();
    q.pop();
    int x = i ? b[i-1] : b[n-1];
    int y = b[i];
    int z = i+1 < n ? b[i+1] : b[0];
    int k = (y-a[i])/(x+z);
    ans += k;
    b[i] -= (x+z)*k;
    add(i ? i-1 : n-1);
    add(i+1 < n ? i+1 : 0);
  }
  /*for (int i = 0; i < n; i++)
    cout << a[i] << ' ';cout << endl;
  for (int i = 0; i < n; i++)
  cout << b[i] << ' ';cout << endl;*/
  for (int i = 0; i < n; i++)
    if (b[i] != a[i]) {
      cout << -1 << endl;
      return 0;
    }
  cout << ans << endl;
}
