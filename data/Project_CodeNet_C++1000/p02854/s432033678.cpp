#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	ll ans = 1e14;
	ll b = 0;
	rep(i, n) {
		b += a[i];
		sum -= a[i];
		ans = min(ans, abs(sum - b));
	}
	dunk(ans);
	return 0;
}