#include <bits/stdc++.h>
//#include "stdc++.h"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = max(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<string, int>> mp;
	while (n--) {
		string s;
		int t;
		cin >> s >> t;
		mp.push_back({s, t});
	}
	string x;
	cin >> x;
	bool ok = false;
	int ans = 0;
	for (auto p : mp) {
		if (ok) {
			ans += p.second;
		} 
		if (p.first == x) ok = true;
	}
	cout << ans << endl;
}
