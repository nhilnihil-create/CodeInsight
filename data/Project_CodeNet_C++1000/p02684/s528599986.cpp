#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> visit(n, 0), loop;
  visit[0] = 1;
  bool is_loop = false;
  int start, cnt = 1, i = 0;
  while (true) {
    visit[a[i]]++;
    if (cnt == k) {
      cout << a[i] + 1 << '\n';
      return 0;
    }
    if (!is_loop && visit[a[i]] == 2) {
      is_loop = true;
      start = cnt;
    }
    if (is_loop) {
      if (visit[a[i]] == 3) break;
      loop.emplace_back(a[i]);
    }
    i = a[i];
    cnt++;
  }
  cout << loop[(k - start) % (int)loop.size()] + 1 << '\n';
  return 0;
}
