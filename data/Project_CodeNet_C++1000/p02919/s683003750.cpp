#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;


int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n) {
		int p;
		cin >> p;
		p--;
		a[p] = i;
	}
	
	set<int> se = { -2,-1,n,n + 1 };
	
	ll ans = 0;

	rep(i, n) {

		ll num = n - i;
		int m = a[n - 1 - i];
		auto itr = se.lower_bound(m);itr++;
		int mr2 = *itr;itr--;
		int mr = *itr;itr--;
		int ml = *itr;itr--;
		int ml2 = *itr;

		if (mr < n)ans += num * (m - ml) * (mr2 - mr);
		if (-1 < ml)ans += num * (mr - m) * (ml - ml2);
		se.insert(m);

	}

	cout << ans << endl;

}