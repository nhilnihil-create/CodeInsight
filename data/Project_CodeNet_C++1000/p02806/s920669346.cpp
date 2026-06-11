#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<string, int>> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	string x;
	cin >> x;
	int st;
	for (int i = 0; i < n; i++) {
		if (p[i].first == x) {
			st = i + 1;
			break;
		}
	}
	int ans = 0;
	for (; st < n; st++) {
		ans += p[st].second;
	}
	cout << ans;
	return 0;
}