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
	ll n, a, b;
	cin >> n >> a >> b;
	
	ll ans = 0LL;
	
	if( (b - a) % 2LL == 0 ) {
		ans = (b - a) / 2LL;
	} else {
		ans = min(a - 1LL, n - b) + 1LL + (b - a - 1LL) / 2LL;
	}
	
	cout << ans << endl;
	
	return 0;
}
