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
	vector<ll> mb(n,0);

	REP(i,n) cin >> ma[i];
	REP(i,n) mb[ma[i]-1]=i+1;
	REP(i,n) cout << mb[i] << " ";
  cout  << endl;
}
