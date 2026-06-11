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
	vector<char> ma(n),mb(1);
	mb[0] = '2';
	REP(i,n) cin >> ma[i];
	REP(i,n) if(ma[i]!=mb[mb.size()-1])mb.push_back(ma[i]);
	// FOR(i,1,mb.size()) cout << mb[i] ;
    cout << mb.size()-1 << endl;
}
