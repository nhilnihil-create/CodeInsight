#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)


int main() {
  int l,r;
  cin >> l >> r;
  int g = r - l;
	l %= 2019;
	r %= 2019;
	int ans = 2020;
	int m = 2020;
	if (l < r )FOR(i,l,r) FOR(j,i+1,r+1) ans = min(ans, (i*j)%2019);
	else ans = 0;
	if (g >= 2019)ans = 0;

  cout << ans << endl;
}