#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; ++i)
#define all(a) (a).begin(), (a).end()

int N;
multiset<int> S, t, c;

int main() {
  cin >> N;
  rep(i, (1 << N)) {
    int j;
    cin >> j;
    S.insert(j);
  }

  t.insert(*S.rbegin());
  S.erase(*S.rbegin());

  rep(i, N) {
    c = multiset<int>(t);
    for (auto e : t) {
      auto it = S.lower_bound(e);
      if (it == S.begin()) {
        cout << "No" << endl;
        return 0;
      }
      c.insert(*prev(it));
      S.erase(prev(it));
    }
    t = c;
  }

  cout << "Yes" << endl;
  return 0;
}
