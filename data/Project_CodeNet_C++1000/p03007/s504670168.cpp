#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  sort(ALL(a));
  multiset<int> neg, pos;
  int ans = 0;
  if (0 <= a[0]) {
    neg.insert(a[0]);
    ans -= a[0];
    REP(i, n) {
      if (i == 0) continue;
      pos.insert(a[i]);
      ans += a[i];
    }
  } else if (a[n - 1] < 0) {
    pos.insert(a[n - 1]);
    ans += a[n - 1];
    REP(i, n) {
      if (i == n - 1) continue;
      neg.insert(a[i]);
      ans -= a[i];
    }
  } else {
    REP(i, n) {
      (a[i] < 0 ? neg : pos).insert(a[i]);
      ans += (a[i] < 0 ? -a[i] : a[i]);
    }
  }
  cout << ans << endl;
  while (1 < pos.size()) {
    int x = *neg.begin();
    neg.erase(neg.find(x));
    int y = *pos.begin();
    pos.erase(pos.find(y));
    neg.insert(x - y);
    cout << x << " " << y << endl;
  }
  while (neg.size()) {
    int x = *pos.begin();
    pos.erase(pos.find(x));
    int y = *neg.begin();
    neg.erase(neg.find(y));
    pos.insert(x - y);
    cout << x << " " << y << endl;
  }
  return 0;
}