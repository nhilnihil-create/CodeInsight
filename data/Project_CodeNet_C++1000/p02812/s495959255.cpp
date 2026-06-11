#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, cnt = 0;
	string s;
	cin >> n >> s;

	for (int left = 0; left < n; left++)
		if (s[left] == 'A' && s[left + 1] == 'B' && s[left + 2] == 'C')
			cnt++;

	cout << cnt << endl;
}
