#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

struct Work {
  int no;
  ll limit;

  bool operator<(const Work& rhs) const { return limit < rhs.limit; }
};

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

  vector<Work> wl(n);
  for (int i = 0; i < n; i++) {
    Work w = {i, b[i]};
    wl[i] = w;
  }
  sort(wl.begin(), wl.end());

  int t = 0;
  for (int i = 0; i < n; i++) {
    int no = wl[i].no;
    t += a[no];
    if (t > wl[i].limit) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
