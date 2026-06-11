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
	
	if( n <= 2 ) {
		cout << *max_element(a.begin(), a.end()) << endl;
		return 0;
	}
	
	sort(a.begin(), a.end(), greater<ll>());
	
	ll ans = 0LL;
	int cnt = 1;
	for(int i = 0; i < n - 2; ++i) {
		if( i < 2 ) {
			ans += a[i];
		} else {
			if( i % 2 == 0 ) cnt++;
			
			ans += a[cnt];
		}
	}
	
	ans += a[1];
	
	cout << ans << endl;
	
	return 0;
}
