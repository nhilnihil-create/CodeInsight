#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 100010

int main() {
  int x, y;
  cin >> x >> y;
  int a, b, c;
  cin >> a >> b >> c;
  ll sum = 0;
  vector<ll> p, q, r;
  ll z;
  for (int i = 0; i < a; i++) {
    cin >> z;
    p.push_back(z);
  }
  for (int i = 0; i < b; i++) {
    cin >> z;
    q.push_back(z);
  }
  for (int i = 0; i < c; i++) {
    cin >> z;
    r.push_back(z);
  }
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  sort(r.begin(), r.end());
  reverse(r.begin(), r.end());
  vector<ll> ms;
  for (int i = 0; i < x; i++) {
    ms.push_back(p[a - x + i]);
  }
  for (int i = 0; i < y; i++) {
    ms.push_back(q[b - y + i]);
  }
  sort(ms.begin(), ms.end());
  int k = 0;
  for (int i = 0; i < ms.size(); i++) {
    if (k < c && r[k] > ms[i]) {
      sum += r[k++];
    } else {
      sum += ms[i];
    }
  }
  cout << sum << "\n";
  return 0;
}