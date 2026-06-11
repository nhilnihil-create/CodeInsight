#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
	int n; string s;
	cin >> n >> s;

	vector<int> val(n, 0);
	forn(i, n-1) val[i+1] = val[i] + 32 - __builtin_clz((i+1) & (-i-1));

	int total = 0;
	forn(i, n) total ^= (s[i] - '1') * int(val[n-1] == val[n-i-1] + val[i]);
	if(s.find('2') != string::npos) total &= 1;
	cout << total << "\n";
}
