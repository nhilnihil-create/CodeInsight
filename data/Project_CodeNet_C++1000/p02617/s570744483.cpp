#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	ll ans = 0;
	rep(i, n - 1) {
		int u, v;
		cin >> u >> v;
		if (u > v)swap(u, v);
		ans += ((ll)i + 1) * (n - i);
		ans -= u * ((ll)n - v + 1);
	}
	ans += n;
	cout << ans << endl;
}