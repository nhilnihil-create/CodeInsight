#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC141-D, 826, 
	int n, m, tmp;
	cin >> n >> m;
	multiset<ll> st;
	ll ans = 0;
	rep(i, n) {
		cin >> tmp;
		st.insert(tmp);
		ans += tmp;
	}
	rep(i, m) {
		ll val = *st.rbegin();
		st.erase(st.find(val));
		ans -= val - val / ll(2);
		st.insert(val / ll(2));
	}
	cout << ans << endl;

	return 0;
}