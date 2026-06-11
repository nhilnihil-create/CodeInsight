#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cassert>
#include <atcoder/all>
#define InfL 2000000000
#define InfLL 4000000000000000000LL
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<db> vd;

int main() {
	int N, Q;
	cin >> N >> Q;
	fenwick_tree<ll> fw(N);
	rep(i, N) {
		ll a;
		cin >> a;
		fw.add(i, a);
	}
	rep(q, Q) {
		int type;
		cin >> type;
		if (type == 0) {
			int p;
			ll x;
			cin >> p >> x;
			fw.add(p, x);
		}
		else {
			int l, r;
			cin >> l >> r;
			ll ans = fw.sum(l, r);
			cout << ans << endl;
		}
	}
	return 0;
}