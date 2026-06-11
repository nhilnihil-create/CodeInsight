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
	ll n, k;
	cin >> n >> k;
	
	if( n % k == 0 ) {
		cout << 0 << endl;
	} else {
		cout << min(n % k, abs(k - n % k)) << endl;
	}
	
	return 0;
}
