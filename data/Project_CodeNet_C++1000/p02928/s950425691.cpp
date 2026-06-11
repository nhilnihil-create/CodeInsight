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
	int n;
	ll k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	ll ans = 0LL;
	for (int i = 0; i < n; i++) {
		ll ainv = 0, rinv = 0;
		
		for(int j = i; j < n; ++j) {
			if( a[i] > a[j] ) rinv++;
		}
		
		for(int j = 0; j < n; ++j) {
			if( a[i] > a[j] ) ainv++;
		}
		
		ans += (k * rinv) % MOD_LL;
		ans %= MOD_LL;
		ans += (ainv % MOD_LL) * ((k * (k - 1LL) / 2LL) % MOD_LL);
		ans %= MOD_LL;
	}
	
	cout << ans << endl;
	
	return 0;
}
