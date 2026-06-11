#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	auto kaibun = [&] (string t) {
		string r = t;
		reverse(t.begin(), t.end());
		return (t == r);
	};
	int n = s.size();
	bool a, b, c;
	a = kaibun(s);
	b = kaibun(s.substr(0,n / 2));
	c = kaibun(s.substr(n - (n / 2), n / 2));
	if (a && b && c) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
