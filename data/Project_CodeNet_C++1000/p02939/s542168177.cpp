#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

//const ll INF = 1e18L + 5;
//const int INF = 1e9 + 5;
//const double pi = 3.14159265358979323846;

void	solve()
{
	string s;
	cin >> s;
	vector<string> ans;
	ans.push_back(string(1, s[0]));
	string l(1, s[0]), r;
	int n = s.size();
	rep2(i, 1, n) {
		r += s[i];
		if (r != l) {
			ans.push_back(r);
			l = r;
			r = "";
		}
	}
	cout << ans.size() << endl;
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
