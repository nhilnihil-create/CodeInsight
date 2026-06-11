#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	string s, ans = "Yes";
	cin >> s;
	if (s[2] != s[3] || s[4] != s[5]) ans = "No";
	cout << ans << endl;
	return 0;
}
