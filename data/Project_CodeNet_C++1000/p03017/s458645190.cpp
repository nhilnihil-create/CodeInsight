#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	string s; cin >> s;
	a--; b--; c--; d--;

	bool res = true;
	rep(i, max(c, d) - a) {
		if(s[a+i] == '#' && s[a+i+1] == '#')
			res = false;
	}
	if(c > d && res) {
		bool ok = false;
		rep(i, d - b + 1) {
			if(s[b+i-1] == '.' && s[b+i] == '.' && s[b+i+1] == '.')
				ok = true;
		}
		res = ok;
	}
	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
