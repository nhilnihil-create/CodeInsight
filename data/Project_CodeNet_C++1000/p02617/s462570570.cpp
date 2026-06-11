#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;



int main()
{
	fastInp;

	ll n;
	cin >> n;

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll vl = (i + 1) * (n - i);
		ans += vl;
	}
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		u--; v--;
		ll vl = (u + 1) * (n - v);
		ans -= vl;
	}

	cout << ans;

	return 0;
}