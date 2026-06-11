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
	vector<ll> ma(n-1);
	REP(i,n-1) cin >> ma[i];
	int ans = 0;
	ans += ma[0]+ ma[n-2];
	REP(i,n-2) ans+=min(ma[i],ma[i+1]); 
  cout << ans << endl;
}
