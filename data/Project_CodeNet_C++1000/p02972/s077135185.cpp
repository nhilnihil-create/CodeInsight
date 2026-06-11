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
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	vector<int> res(n + 1);
	vector<int> ans;
	for (int i = n; i >= 1; --i) {
		int tmp = 0;
		for (int j = i + i; j <= n; j += i) {
			tmp += res[j];
		}
		if (a[i]) {
			if (tmp % 2 == 0) res[i] = 1;
		}
		else {
			if (tmp % 2 != 0) res[i] = 1;
		}
		if (res[i] == 1) ans.push_back(i);
	}
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	for (int c : ans) cout << c << "\n";
	return 0;
}