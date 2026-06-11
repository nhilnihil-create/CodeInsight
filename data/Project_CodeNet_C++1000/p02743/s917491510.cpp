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
	ll a, b, c;
	cin >> a >> b >> c;
	
	ll x = c - a - b;
	
	if( a + b < c && x * x > 4 * a * b ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	return 0;
}
