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

template<typename T>
T gcd(T a, T b) {
	if( a < b ) swap(a, b);
	
	T r;
	while( r = a % b ) {
		a = b;
		b = r;
	}
	
	return b;
}

int main(void) {
	int m;
	cin >> m;
	
	int ans = 0;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= m; ++j) {
			for(int k = 1; k <= m; ++k) {
				ans += gcd(i, gcd(j, k));
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
