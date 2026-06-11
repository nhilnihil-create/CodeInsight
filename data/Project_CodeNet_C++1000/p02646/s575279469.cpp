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
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	ll a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;
	
	if( v <= w ) {
		cout << "NO" << endl;
		return 0;
	}
	
	if( abs(b - a) <= abs(v - w) * t ) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
