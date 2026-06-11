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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n;
	cin >> n;
	
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	ll ans = 0;
	ll factor = 1;
	
	for(int i = 0; i < 60; ++i) {
		ll one = 0;
		ll zero = 0;
		
		for(int j = 0; j < n; ++j) {
			if( a[j] & (1LL << i) ) {
				one++;
			} else {
				zero++;
			}	
		}
		
		ans += (one * zero) % MOD_LL * (factor % MOD_LL);
		ans %= MOD_LL;
		factor *= 2;
		factor %= MOD_LL;
	}

	cout << ans << endl;
	
	return 0;
}
