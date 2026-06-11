#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string S;
	cin >> S;

	string a, b;
	int m = S.size() / 2;

	if (S.size() & 1) {
		a = S.substr(0, m);
		b = S.substr(m + 1, m);
	}
	else {
		a = S.substr(0, m);
		b = S.substr(m, m);
	}
	reverse(b.begin(), b.end());

	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) ans++;
	}

	cout << ans << endl;
}