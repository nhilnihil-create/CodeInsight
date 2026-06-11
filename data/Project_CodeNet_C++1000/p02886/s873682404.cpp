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
	cin >> n;
	
	vector<ll> d(n);
	for(int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	
	ll ans = 0LL;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			ans += d[i] * d[j];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
