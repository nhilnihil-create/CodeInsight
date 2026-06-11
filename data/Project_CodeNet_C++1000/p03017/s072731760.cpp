#include<bits/stdc++.h>
using namespace std;

int main() {	
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	string s;
	cin >> s;

	a--; b--; c--; d--;

	auto f = [&](int start, int end) {
		for (int i = start; i < end; i++) {
			if (s[i] == '#' && s[i + 1] == '#') {
				return true;
			}
		}
		return false;
	};

	if (f(a, c) || f(b, d)) {
		cout << "No" << endl;
		return 0;
	}

	if (c < d) {
		cout << "Yes" << endl;
		return 0;
	}

	if (s[b + 1] != '#' && s[b - 1] != '#') {
		cout << "Yes" << endl;
		return 0;
	}

	s = s + "#";


	int cnt = 0;
	for (int i = b; i <= d; i++) {
		if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
			cout << "Yes" << endl;
			return 0;
		}	
	}
	
	cout << "No" << endl;
	return 0;
}
