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
	ll n;
	cin >> n;
	
	ll tmp = n;
	string ans = "";
	
	while( tmp ) {
		ans += (char)(((tmp - 1) % 26) + 'a');
		tmp = (tmp - 1) / 26;
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans << endl;
	
	return 0;
}
