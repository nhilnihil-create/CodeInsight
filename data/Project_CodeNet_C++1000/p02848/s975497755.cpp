
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
	int x;
	string a;
	cin >> x;
	cin >> a;
	int n = a.length();
	for (int i = 0; i < n; ++i)
	{
		if (((int)a[i]) - 65 + x > 25) {
			cout << (char)(((int)a[i]) + x - 26);
		} else {
			cout << (char)(((int)a[i]) + x);
		}
		
	}
}
 
