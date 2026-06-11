#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#define INF 1000000009
#define LINF 1000000000000000009
#define EPS 1e-10
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}
	set<ll> st;
	st.insert(-1); st.insert(n);
	ll ans = 0;
	for (ll i = n; i >= 1; i--) {
		ll k = b[i];
		auto itr = st.lower_bound(k);
		ll r = *itr; itr--;
		ll l = *itr; itr++;
		if (r != n) {
			itr++;
			ll r2 = *itr;
			ans += (r2 - r)*(k - l)*i;
			itr--;
		}
		itr--;
		if (l != -1) {
			itr--;
			ll l2 = *itr;
			ans += (l - l2)*(r - k)*i;
			itr++;
		}
		st.insert(k);
		//cout << ans << endl;
	}
	cout << ans << endl;
}