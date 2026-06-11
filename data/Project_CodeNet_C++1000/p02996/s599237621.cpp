#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

struct Work {
  int take;
  ll limit;

  bool operator<(const Work& rhs) const { return limit < rhs.limit; }
};

int main() {
  int n;
  cin >> n;
  vector<Work> w(n);
  for (int i = 0; i < n; i++) cin >> w[i].take >> w[i].limit;

  sort(w.begin(), w.end());

  int t = 0;
  for (int i = 0; i < n; i++) {
    t += w[i].take;
    if (t > w[i].limit) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
