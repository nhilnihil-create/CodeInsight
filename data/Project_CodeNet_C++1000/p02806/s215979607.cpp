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
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int n;
	cin >> n;
	
	vector<string> s(n);
	vector<int> t(n);
	
	for(int i = 0; i < n; ++i) {
		cin >> s[i] >> t[i];	
	}
	
	string x;
	cin >> x;
	
	int st = 0;
	for(int i = 0; i < n; ++i) {
		if( s[i] == x ) {
			st = i;
			break;
		}
	}
	
	int ans = 0;
	for(int i = st + 1; i < n; ++i) {
		ans += t[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
