#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b, c, d;
	string s;
	cin >> n >> a >> b >> c >> d >> s;

	int mx = max(c, d);
	for (int i = a; i < mx; i++) {
		if (s[i - 1] == '#' && s[i - 1] == s[i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	if (c < d) {
		cout << "Yes" << endl;
	} else {
		for (int i = b - 2; i < d - 1; i++) {
			if (s[i] == '.' && s[i] == s[i + 1] && s[i] == s[i + 2]) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
	}

	return 0;
}