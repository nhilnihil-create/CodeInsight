#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
const int N = 1005;

pair<int, int> loc[N][N];
int mu[N][N], day[N][N];
int n, played;
bool done[N][N];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			int a; cin >> a;
			--a;
			mu[i][j] = a;
			loc[i][a] = {i, j};
		}
	}
	
	list<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		day[i][0] = 1;
		q.push_back({i, 0});
	}
	
	int ans = 0;
	bool changed;
	do {
		changed = false;
		for (auto it = q.begin(); it != q.end();) {
			auto nxt = next(it, 1);
			pair<int, int> v = *it;
			int r = v.first, c = v.second;
			if (done[r][c]) {
				it = q.erase(it);
				continue;
			}
			int match = mu[r][c];
			pair<int, int> muloc = loc[match][r];
			if (day[muloc.first][muloc.second]) {
				changed = true;
				// cout << r << ' '  << c << '\n';
				done[r][c] = true;
				done[muloc.first][muloc.second] = true;
				++played;
				
				int md = max(day[muloc.first][muloc.second], day[r][c]);
				day[muloc.first][muloc.second] = day[r][c] = md;
				
				ans = max(ans, md);
				day[r][c + 1] = md + 1;
				day[muloc.first][muloc.second + 1] = md + 1;
				if (c + 1 < n - 1) q.push_back({r, c + 1});
				if (muloc.second + 1 < n - 1) q.push_back({muloc.first, muloc.second + 1});
				
				q.erase(it);
			}
			it = nxt;
		}
	} while (changed);
	
	if (played == n * (n - 1) / 2) cout << ans;
	else cout << -1;
}
