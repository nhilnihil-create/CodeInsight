#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	string result = "";
	for (int i = 0; i < n; i++) {
		result += s[i];
		result += t[i];
	}
	cout << result << '\n';
	return 0;
}
