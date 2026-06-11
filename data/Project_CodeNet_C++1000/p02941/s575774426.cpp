#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;

int main() {
  cin >> n;
  vector<int> a(n), b(n);
  range(i, 0, n) {
    cin >> a[i];
  }
  range(i, 0, n) {
    cin >> b[i];
  }
  vector<int> pos;
  range(i, 0, n) {
    if(a[i] == b[i]) continue;
    else {
      int s = b[(i + n - 1) % n] + b[(i + 1) % n];
      if(b[i] > s) pos.push_back(i);
    }
  }
  auto pull = [&](int p) {
    if(b[p] == a[p]) return;
    int pr = (p + n - 1) % n, nxt = (p + 1) % n;
    if(b[p] > b[pr] + b[nxt]) pos.push_back(p);
  };
  long long cnt = 0;
  while(pos.size()) {
    int p = pos.back();
    pos.pop_back();
    int pr = (p + n - 1) % n, nxt = (p + 1) % n;
    int s = b[pr] + b[nxt];
    int c = b[p] % s;
    if(a[p] >= c) {
      if(a[p] % s == c) {
        cnt += (b[p] - a[p]) / s;
        b[p] = a[p];
      } else {
        cout << -1;
        return 0;
      }
    } else {
      cnt += (b[p] - c) / s;
      b[p] = c;
    }
    pull(pr);
    pull(nxt);
  }
  range(i, 0, n) {
    if(a[i] != b[i]) {
      cout << -1;
      return 0;
    }
  }
  cout << cnt;
  return 0;
}
