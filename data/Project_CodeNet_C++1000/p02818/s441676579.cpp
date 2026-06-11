
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
 
#define coutv(v) for (int i = 0; i < (v).size(); ++i) cout << v[i] << ' '; cout << endl;
#define coutvv(v) for (int i = 0; i < (v).size(); ++i) {for (int j = 0; j < (v[i]).size(); ++j) cout << v[i][j] << ' '; cout << endl;}
#define debugv(v) {for (int i = 0; i < (v).size(); ++i) cerr << v[i] << ' '; cerr << endl;}
#define debugvv(v) {for (int i = 0; i < (v).size(); ++i) {for (int j = 0; j < (v[i]).size(); ++j) cerr << v[i][j] << ' '; cerr << endl;}}
#define TC int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
typedef long long ll;
 



int main() {
	ll a,b,c;
	cin >> a >> b >> c;
	if (c >= a) {
		c -= a;
		a = 0;
	} else {
		a -= c;
		c = 0;
	}
	if (c > 0) {
		b -= min(c,b);
	}
	cout << a << " " << b;
}
 
