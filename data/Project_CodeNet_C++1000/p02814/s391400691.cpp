#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <stack>
#include <set>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

void solve() {
	ll n, m; cin >> n >> m;
	vector<ll> v(n);
	for (auto &i : v)cin >> i, i /= 2;
	ll cur = 1;
	for (auto i : v)cur = lcm(cur, i);
	for (auto i : v) {
		if ((cur / i) % 2 == 0) {
			cout << 0; return ;
		}
	}

	cout << (m / cur / 2) + (m / cur) % 2 << endl;



}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t; cin >> t;
	// while (t--)
	solve();

}