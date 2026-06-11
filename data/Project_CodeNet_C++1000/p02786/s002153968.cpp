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
T mypow(T a, T p) {
	T ret = 1;
	while( p ) {
		if( p & 1 ) {
			ret *= a;
		}
		
		a *= a;
		p >>= 1;
	}
	
	return ret;
}

int main(void) {
	ll h;
	cin >> h;
	
	ll cnt = 0LL;
	ll tmp = h;
	while( tmp ) {
		tmp /= 2LL;
		cnt++;
	}
	
	ll ans = 0LL;
	for(ll i = 0; i < cnt; ++i) {
		ans += mypow(2LL, i);
	}
	
	cout << ans << endl;
	
	return 0;
}
