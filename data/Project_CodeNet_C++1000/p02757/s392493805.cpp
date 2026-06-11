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
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	vector<int> sum(n + 1);
	int ten = 1;
	for (int i = n - 1; i >= 0; --i) {
		int a = (s[i] - '0') * ten % p;
		sum[i] = (sum[i + 1] + a) % p;
		ten *= 10; ten %= p;
	}
	if (p == 2 || p == 5) {
		ll ans = 0;
		rep(i, n)
			if ((s[i] - '0') % p == 0) ans += (i + 1);
		printf("%lld\n", ans);
	}
	else {
		vector<int> res(p);
		ll ans = 0;
		for (int i = n; i >= 0; --i) {
			ans += res[sum[i]];
			res[sum[i]]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
