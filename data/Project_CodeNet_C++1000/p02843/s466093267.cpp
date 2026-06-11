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
	int x;
	cin >> x;
	vector<int> items;
	int price = 100;
	rep(i, 6) items.push_back(price + i);
	rep(bit, 1 << 6) {
		int total = 0;
		rep(i, 6) {
			if (bit >> i & 1) {
				total += items[i];
			}
		}
		if (total && ((x % total == 0) || (x % total >= 100 && x % total <= 105))) {
			cout << 1 << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}