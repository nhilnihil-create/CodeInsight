#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
string s;
int n;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	a --; b --; c --; d --;
	cin >> s;
	vector <bool> fp(n), sp(n);
	vector <int> dp(n);
	fp[a] = sp[b] = 1;
	for (int i=1; i<n; i++) {
		if (s[i] == '#') continue;
		if (fp[i-1] || (i > 1 && fp[i-2])) {
			fp[i] = 1;
		}
		if (sp[i-1] || (i > 1 && sp[i-2])) {
			sp[i] = 1;
		}
	}
	if (d > c) {
		if (fp[c] && sp[d]) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		return 0;
	}
	int tec = 0;
	for (int i=b; i<=d+1; i++) {
		if (s[i] ==  '#') {
			tec = 0;
			continue;
		}
		tec ++;
		if (tec >= 3) break;
	}
	if (s[b+1] == '.' && s[b-1] == '.') tec = 3;
	cout << (tec >= 3 && fp[c] && sp[d] ? "Yes" : "No");
	return 0;
}