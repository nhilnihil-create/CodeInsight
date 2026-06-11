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
const ll linf = (ll)4e18;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	s += s;
	int n = s.size();
	vector<set<int>> is(26);
	rep(i, n) is[s[i] - 'a'].insert(i);
	int k = t.size();
	int pos = -1;
	ll ans = 0;
	bool ok = 1;
	rep(i, k) {
		int num = t[i] - 'a';
		if (is[num].size() == 0) {
			ok = 0;
			break;
		}
		auto itr = is[num].lower_bound(pos + 1);
		if (itr == is[num].end()) {
			ans += n - pos;
			ans += *is[num].begin();
			pos = *is[num].begin();
		}
		else {
			ans += *itr - pos;
			pos = *itr;
		}
	}
	if (ok) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}
