#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;	

int main() {
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	
	REP(i, k) {
		if (a >= b) {
			b *= 2;
		}
		else if (b >= c) {
			c *= 2;
		}
	}
	if (a < b && b < c) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
