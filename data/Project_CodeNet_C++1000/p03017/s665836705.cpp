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

bool check(int x, int y, string s) {
	for(int i = x; i < y; ++i) {
		if( s.substr(i, 2) == "##" ) return false;
	}
	
	return true;
}

int main(void) {
	int n, a, b, c, d;
	string s;
	cin >> n >> a >> b >> c >> d >> s;
	
	a--; b--; c--; d--;
	
	if( !check(a, c, s) || !check(b, d, s) ) {
		cout << "No" << endl;
		return 0; 
	}
	
	if( c < d ) {
		cout << "Yes" << endl;
	} else if( c > d ) {
		for(int i = b; i <= d; ++i) {
			if( s.substr(i - 1, 3) == "..." ) {
				cout << "Yes" << endl;
				return 0;
			}				
		}
		
		cout << "No" << endl;
	}

	return 0;
}
