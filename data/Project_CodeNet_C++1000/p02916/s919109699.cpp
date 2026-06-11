#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n;
	cin >> n;
	vector<ll> ma(n),mb(n),mc(n-1);
	REP(i,n) cin >> ma[i];
	REP(i,n) cin >> mb[i];
	REP(i,n-1) cin >> mc[i];

	int ans = 0;
	int t = -1;
	REP(i,n) {
		if(t+1 == ma[i]) ans += mc[ma[i]-2];
		ans += mb[ma[i]-1];
		t = ma[i];

	}

  cout << ans << endl;
}
