#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

void solve_test() {
	string s;
	cin >> s;
	int n = s.length();
	if (s[n - 1] == 's')
		cout << s << "es" << '\n';
	else
		cout << s << "s" << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
