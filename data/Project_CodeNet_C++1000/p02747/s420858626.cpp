#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string s; cin >> s;
	const int sz = s.length();
	if (sz & 1) {
		cout << "No" << endl;
		return 0;
	}
	int ptr = 0;
	while (ptr < sz) {
		string sub = s.substr(ptr, 2);
		if (sub != "hi") {
			cout << "No" << endl;
			return 0;
		}
		ptr += 2;
	}
	cout << "Yes" << endl;
	return 0;
}