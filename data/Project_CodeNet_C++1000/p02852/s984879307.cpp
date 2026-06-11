#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	reverse(all(s));

	vi ans;
	int p = 0;
	while (true) {
		int k = min(p + m, n);
		while (p < k) {
			if (s[k] == '0') {
				ans.push_back(k - p);
				break;
			}
			k--;
		}
		if (p == k) {
			cout << -1 << endl;
			return 0;
		}
		p = k;
		if (p == n)break;
	}

	rep(i, ans.size()) {
		cout << ans[ans.size() - 1 - i];
		if (i < ans.size() - 1)cout << " ";
		else cout << endl;
	}
}