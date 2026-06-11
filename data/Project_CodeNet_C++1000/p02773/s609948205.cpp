#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool mada (string a, string b) {
	int aux = 0;
	while (aux < min(a.size(), b.size()) && a[aux] == b[aux]) aux++;
	if (aux == min(a.size(), b.size())) aux--;
	return a[aux] < b[aux];
}

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	map <string, int> h;
	for (int i=1; i<=n; i++) {
		cin >> s;
		h[s]++;
	}
	int mx = 0;
	for (auto it : h) {
		mx = max(mx, it.second);
	}
	vector <string> ans;
	for (auto it : h) {
		if (it.second == mx) {
			ans.push_back(it.first);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}