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
	int n, k, s;
	cin >> n >> k >> s;
	
	for(int i = 0; i < k; ++i) {
		cout << s << " ";
	}
	
	if( s != 1e9 ) {
		for(int i = 0; i < n - k; ++i) {
			cout << 1000000000 << " ";
		}
	} else {
		for(int i = 0; i < n - k; ++i) {
			cout << 1 << " ";
		}
	}
	
	cout << endl;
	
	return 0;
}
