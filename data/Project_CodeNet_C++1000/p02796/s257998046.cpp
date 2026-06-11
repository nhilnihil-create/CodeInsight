#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int) (n); i++)
#define REP1(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector <pair <int, int> > lx(n);
  REP(i, n) {
	int x, l;
	cin >> x >> l;
	lx[i] = make_pair(x + l, x - l);
  }
  sort(all(lx));
  int l   = -2e9;
  int ans = 0;
  REP(i, n) {
	if (l <= lx[i].second) {
		ans++;
		l = lx[i].first;
	  }
  }
  cout << ans << endl;
  return 0;
}
