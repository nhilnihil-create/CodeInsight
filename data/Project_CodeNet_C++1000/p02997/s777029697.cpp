#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int r = (n - 1) * (n - 2) / 2;
	if (k > r) {
		cout << -1 << endl;
		return 0;
	}
	vector<P> ans;
	rep(i, n - 1) ans.emplace_back(i + 1, n);
	vector<P> edge;
	rep(i, n - 1)rep(j, i) edge.emplace_back(i + 1, j + 1);
	rep(i, r -  k) ans.emplace_back(edge[i]);
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i].first << ' '<< ans[i].second << endl;
	return 0;
}