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
	
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, n)cin >> a[i];

	ll l = 0;
	ll r = 1e10;

	while (r - l > 1) {

		ll c = (r + l) / 2;
		ll cnt = 0;

		rep(i, n)cnt += (a[i] + c - 1) / c - 1;

		if (cnt <= k)r = c;
		else l = c;
	}

	cout << r << endl;

}