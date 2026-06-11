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
	vector<char> ma(n),mb(n),ans(n+n);
	REP(i,n) cin >> ma[i];
	REP(i,n) cin >> mb[i];
	REP(i,n+n){
		if(i%2==0)ans[i] = ma[i/2];
		else ans[i] = mb[i/2];
	}
	REP(i,n+n) cout << ans[i];
  cout << endl;
}
