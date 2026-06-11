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
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, d, a;
	cin >> n >> d >> a;
	V<P> monster(n);
	rep(i, n) {
		int x, h;
		cin >> x >> h;
		monster[i] = P(x, h);
	}
	
	sort(all(monster));

	V<ll> use(n);
	V<ll> usesum(n + 1);

	rep(i, n) {
		int k = lower_bound(all(monster), P(monster[i].first - 2 * d, 0)) - monster.begin();
		int bomb = usesum[i] - usesum[k];
		use[i] = max((monster[i].second + a - 1) / a - bomb, 0);
		usesum[i + 1] = usesum[i] + use[i];
	}

	cout << usesum[n] << endl;

}