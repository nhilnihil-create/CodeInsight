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
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	int point = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		point += a[i];
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if( 4 * m * a[i] >= point ) ans++;
	}
	
	if( ans >= m ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
