#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;	

int main() {
	int n; cin >> n;
	string s; cin >> s;
	bool echo = true;
	if (n % 2) echo = false;
	REP(i, n / 2) if (s[i] != s[n / 2 + i]) echo = false;
	cout << (echo ? "Yes" : "No") << endl;
;}
