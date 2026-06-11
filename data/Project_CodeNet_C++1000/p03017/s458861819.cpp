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
	int n, a, b, c, d;
	string s;
	cin >> n >> a >> b >> c >> d >> s;
	a--; b--;
	c--; d--;
	
	auto can_reach = [&](int start, int goal) {
		for(int i = start; i < goal; ++i) {
			if( s[i] == '#' && s[i + 1] == '#' ) return false;
		}
	
		return true;
	};
	
	if( !can_reach(a, c) || !can_reach(b, d) ) {
		cout << "No" << endl;
		return 0;
	}
	
	if( c < d ) {
		cout << "Yes" << endl;
	} else if( c > d ) {
		bool threeDot = false;
		
		for(int i = b; i <= d; ++i) {
			if( s.substr(i - 1, 3) == "..." ) {
				threeDot = true;
			}
		}
	
		if( threeDot ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}	
	
	return 0;
}
