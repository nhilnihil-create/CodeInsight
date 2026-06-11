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
	string s;
	cin >> s;
	
	int n = (int)s.size();
	int ans = 0;
	for(int i = 0; i < n / 2; ++i) {
		if( s[i] != s[n - i - 1] ) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
