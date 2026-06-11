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
	vector<char> ma(n);
	REP(i,n) cin >> ma[i];
	int f = 1;
	int F = n/2;
	f *= (n%2==0);
	REP(i,F) if(ma[i] != ma[i+F]) f=0;
	string ans = "No";
	if (f) ans = "Yes";
  cout << ans << endl;
}
