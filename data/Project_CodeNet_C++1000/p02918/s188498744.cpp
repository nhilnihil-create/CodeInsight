#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k; cin >> n >> k;
	string s; cin >> s;
	int score = 0;
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == s[i]) score++;
	}
	cout << min(n - 1, score + 2 * k) << endl;
	return 0;
}