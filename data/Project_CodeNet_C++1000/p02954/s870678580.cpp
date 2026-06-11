#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((int)(x).size())
#define REP(i, n) for(ll i = 0; i < (n); i++)
#define REPR(i, n) for (ll i = (n); i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << res << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, l, r)  (a).begin()+(l),(a).begin()+(r)


int main() {
	string s;
	cin >> s;
	int i = 0;
	int lasti = -1;
	vector<int> res(s.size());
	while (1) {
		int numofR = 0, numofL = 0;
		while (s[i] == 'R') {
			numofR++;
			i++;
		}
		int left = i - 1;
		int right = i;
		while (s[i] == 'L') {
			numofL++;
			i++;
			if (i == s.size()) break;
		}
		res[right] = numofR / 2 + (numofL + 1) / 2;
		res[left] = numofR + numofL - res[right];
		if (i == s.size()) break;
	}
	FOR(i, 0, s.size()-1) {
		cout << res[i];
		if (i == s.size()) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
	return(0);
}