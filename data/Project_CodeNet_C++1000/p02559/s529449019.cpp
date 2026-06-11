#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>
#include<functional>
#include<unordered_set>
#include<unordered_map>
#include<atcoder/all>

using ll=long long;
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

using namespace std;
int main()
{
	ll N, Q;
	cin >> N >> Q;
	atcoder::fenwick_tree<ll> ft(N);
	rep(i, 0, N) {
		ll a;
		cin >> a;
		ft.add(i, a);
	}
	rep(i, 0, Q) {
		ll t;
		cin >> t;
		if (t) {
			ll l, r;
			cin >> l >> r;
			cout << ft.sum(l, r) << endl;
		}
		else {
			ll p, x;
			cin >> p >> x;
			ft.add(p, x);
		}
	}

	return 0;
}

