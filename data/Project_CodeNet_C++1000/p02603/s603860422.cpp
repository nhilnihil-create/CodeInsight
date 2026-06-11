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
	
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	a.push_back(0LL);
	ll ans = 1000LL, money = 1000LL, stock = 0LL;
	
	for(int i = 0; i < n; ++i) {		
		if( i > 0 && a[i - 1] < a[i] && stock > 0 ) {
			money += a[i] * stock;
			stock = 0;
			ans = max(ans, money);
		}
		
		if( i < n && a[i] < a[i + 1] && money > a[i] ) {
			stock = money / a[i];
			money %= a[i];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
