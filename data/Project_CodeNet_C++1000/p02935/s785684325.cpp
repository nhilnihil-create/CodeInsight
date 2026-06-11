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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	double ans = (double)v[0];
	for(int i = 1; i < n; ++i) {
		ans = (ans + (double)v[i]) / 2.0;
	}
	
	printf("%.10f\n", ans);
	
	return 0;
}
