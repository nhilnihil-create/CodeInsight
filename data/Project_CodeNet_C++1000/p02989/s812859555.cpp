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
	
	vector<int> d(n);
	for(int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	
	sort(d.begin(), d.end());
	
	int ans = 0;
	for(int i = 1; i <= d.back(); ++i) {
		int x = lower_bound(d.begin(), d.end(), i) - d.begin();
		
		if( x == n / 2 ) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
