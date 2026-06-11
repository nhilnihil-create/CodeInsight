#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int c = count(s.begin(), s.end(), 'R');
	if (c == 3)
		cout << 3 << "\n";
	else if (c == 2 && s[1] != 'S')
		cout << 2 << "\n";
	else if (c == 0)
		cout << 0 << "\n";
	else
		cout << 1 << "\n";

	return 0;
}
