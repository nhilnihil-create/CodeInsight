#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define boost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	boost;
	int count = 0;
	string s, t;
	cin >> s >> t;
	int len = s.length();
	FOR(i, 0, len) {
		if (s[i] != t[i]) {count += 1;}
	}
	cout << count << endl;
}
