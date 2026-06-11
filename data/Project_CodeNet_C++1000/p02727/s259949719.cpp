#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	
	vector<ll> p(a), q(b), r(c);
	for(int i = 0; i < a; ++i) {
		cin >> p[i];
	}
	
	for(int i = 0; i < b; ++i) {
		cin >> q[i];
	}
	
	for(int i = 0; i < c; ++i) {
		cin >> r[i];
	}
	
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	sort(r.begin(), r.end());
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	
	for(int i = a - 1; i > a - x - 1; i--) {
		pq.push(p[i]);
	}
	
	for(int i = b - 1; i > b - y - 1; i--) {
		pq.push(q[i]);
	}
	
	while( r.size() && r.back() > pq.top() ) {
		pq.pop();
		pq.push(r.back());
		r.pop_back();
	}
	
	
	ll ans = 0LL;
	//while( !pq.empty() ) {
	while( pq.size() ) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans << endl;
	
	return 0;
}
