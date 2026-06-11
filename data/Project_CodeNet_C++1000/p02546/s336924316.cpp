#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	if (s[(int)s.size()-1] != 's') {
		cout << s << 's';
	} else {
		cout << s <<  "es";
	}
	return 0;
}
