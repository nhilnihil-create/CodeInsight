
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
	int n;
	cin >> n;
	string a;
	cin >> a;
	int cnt = 1;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] != a[i-1]) {
			cnt += 1;
		}
	}
	cout << cnt;
}
 
