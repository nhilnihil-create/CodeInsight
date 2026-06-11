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
	vector<ll> ma(n);
	REP(i,n) cin >> ma[i];
	ma.push_back(1000000200);
	int f = 1;
	string ans = "Yes";
	REP(i,n) {
		if (f) ma[i]-=1;
		if (ma[i]-ma[i+1]>=1) ans = "No";
		else if (ma[i] - ma[i+1] == 0) f = 0;
		else f = 1;

	}

  cout << ans << endl;
}
