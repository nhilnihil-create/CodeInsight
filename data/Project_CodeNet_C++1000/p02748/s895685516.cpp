#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int) (n); i++)
#define REP1(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
using ll = long long;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector <int> a(A);
  vector <int> b(B);
  int am = 1e9;
  int bm = 1e9;
  REP(i, A) {
	cin >> a[i];
	am = min(am, a[i]);
  }
  REP(i, B) {
	cin >> b[i];
	bm = min(bm, b[i]);
  }
  int ans = am + bm;
  REP(i, M) {
	int x, y, c;
	cin >> x >> y >> c;
	ans = min(ans, a[x - 1] + b[y - 1] - c);
  }
  cout << ans << endl;
  return 0;
}
