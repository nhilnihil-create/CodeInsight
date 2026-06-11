#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int main() {
	
	int n, k;
	cin >> n >> k;
	
	if (k > (n - 1) * (n - 2) / 2) {
		cout << -1 << endl;
		return 0;
	}
	
	V<P> ans;
	int now = 0;

	rep1(i, n - 1) {
		int u = 1;
		ans.push_back(P(u, i + 1));
		now += i - 1;
		while (now > k) {
			u++;
			ans.push_back(P(u, i + 1));
			now--;
		}
	}

	cout << ans.size() << endl;
	for (auto p : ans)cout << p.first << " " << p.second << endl;

}