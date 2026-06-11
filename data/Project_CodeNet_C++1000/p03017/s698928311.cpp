#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool pass(string s, int b, int d) {
	bool x = true;
	for (int i = b - 1; i < d - 2; i++) {
		if (s.at(i) == '#' && s.at(i + 1) == '#') {
			x = false;
			break;
		}
	}
	return x;
}
bool over(string s, int b, int d) {
	bool x = false;
	for (int i = b - 2; i < d - 1; i++) {
		if (s.at(i) == '.' && s.at(i + 1) == '.' && s.at(i + 2) == '.') x = true;
	}
	return x;
}
int main() {
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	string s; cin >> s;
	if (c < d) {
		bool x = pass(s, b, d);
		bool y = pass(s, a, c);
		if (x && y)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		bool x = over(s, b, d);
		if (!x)cout << "No" << endl;
		else {
			bool y = pass(s, a, d);
			bool z = pass(s, b, c);
			if (y && z)cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}