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
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, p;
	string s;
	cin >> n >> p >> s;

	ll ans = 0;

	if (p == 2 || p == 5) { rep(i, n)if ((s[i] - '0') % p == 0)ans += (ll)i + 1; }
	else {
		int x = 1, k = 0;
		vi cnt(p, 0);cnt[0]++;
		rep(i, n) {
			k += (s[n - 1 - i] - '0') * x;k %= p;
			cnt[k]++;
			x = x * 10 % p;
		}
		rep(i, p) ans += cnt[i] * ((ll)cnt[i] - 1) / 2;
		
	}

	cout << ans << endl;

}