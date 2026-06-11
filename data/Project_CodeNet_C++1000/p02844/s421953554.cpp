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
	string s;
	cin >> n >> s;
	
	int ans = 0;
	for(int i = 0; i < 1000; ++i) {
		string tmp;
		
		if( i == 0 ) {
			tmp = "000";
		} else if( i > 0 && i < 10 ) {
			tmp = "00";
			tmp += (char)(i + '0');
		} else if( i >= 10 && i < 100 ) {
			tmp = '0';
			tmp += to_string(i);
		} else {
			tmp = to_string(i);
		}
		
		int k = 0;
		for(int j = 0; j < n; ++j) {
			if( s[j] == tmp[k] ) k++;
			if( k == 3 ) break;
		}
		
		if( k == 3 ) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
