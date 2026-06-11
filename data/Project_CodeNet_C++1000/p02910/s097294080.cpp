#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	string s; cin >> s;
	int S = s.size();
	REP(i, S) {
		if ((i + 1)  % 2 == 0 && s.at(i) != 'L' && s.at(i) != 'U' && s.at(i) != 'D') {
			cout << "No" << endl;
			return 0;
		}
		else if((i + 1) % 2 == 1 && s.at(i) != 'R' && s.at(i) != 'U' && s.at(i) != 'D') {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
