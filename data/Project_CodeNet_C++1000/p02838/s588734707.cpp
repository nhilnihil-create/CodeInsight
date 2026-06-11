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
	
	vector< vector<ll> > x(60, vector<ll>(2, 0));
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 60; ++j) {
			if( a[i] & (1LL << j) ) {
				x[j][1]++;
			} else {
				x[j][0]++;
			}	
		}
	}
	
	ll ans = 0;
	ll factor = 1;
	
	for(int i = 0; i < 60; ++i) {
		ans += (x[i][0] * x[i][1]) % MOD_LL * (factor % MOD_LL);
		ans %= MOD_LL;
		factor = (factor * 2) % MOD_LL;
	}
	
	cout << ans << endl;
	
	return 0;
}
