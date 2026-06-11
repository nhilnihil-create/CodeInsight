#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	int n, m;
	cin >> n >> m;
	string result = "";
	for (int i = 0; i < n; i++)
		result += "?";
	for (int i = 0; i < m; i++) {
		int s;
		char c;
		cin >> s >> c;
		s--;
		if (result[s] != '?' && result[s] != c) {
			cout << "-1\n";
			return 0;
		}
		result[s] = c;
	}
	if (n == 1) {
		if (result[0] == '?')
			result[0] = '0';
	} else {
		if (result[0] == '?')
			result[0] = '1';
		else if (result[0] == '0') {
			cout << "-1\n";
			return 0;
		}
		for (int i = 1; i < n; i++)
			if (result[i] == '?')
				result[i] = '0';
	}
	cout << result << '\n';
	return 0;
}
