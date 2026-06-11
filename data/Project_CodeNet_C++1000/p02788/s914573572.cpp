#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

vector<pair<ll, ll> > v;
ll n, d, a;

int main() {
	cin >> n >> d >> a;
	for (int i = 0; i < n; i++) {
		ll x, h;
		cin >> x >> h;
		v.push_back(make_pair(x, h));
	}
	sort(v.begin(), v.end());
	ll j = -1;
	ll ret = 0;
	ll sum = 0;
	vector<pair<ll, ll> > bombs;
	for (int i = 0; i < n; i++) {
		pair<ll, ll> cur = v[i];
		while ((j + 1 < bombs.size()) && (bombs[j + 1].first <= cur.first - 2 * d - 1)) {
			j++;
			sum -= bombs[j].second * a;	
		}
		ll b = max((cur.second + a - 1 - sum) / a, (ll)0);
		sum += b * a;
		ret += b;
		bombs.push_back(make_pair(cur.first, b));
	}
	cout << ret << endl;

	return 0;
}
