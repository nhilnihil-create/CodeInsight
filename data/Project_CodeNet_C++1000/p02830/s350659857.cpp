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
	string s, t;
	cin >> n >> s >> t;
	
	int a = 0, b = 0;
	for(int i = 0; i < 2 * n; ++i) {
		if( i % 2 == 0 ) {
			cout << s[a];
			a++;
		} else {
			cout << t[b];
			b++;
		}
	}
	
	cout << endl;
	
	return 0;
}
