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
	int k, n;
	cin >> k >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<int> dis(n, 0);
	for(int i = 0; i < n - 1; ++i) {
		dis[i] = abs(a[i + 1] - a[i]);
	}
	
	dis[n - 1] = k - a[n - 1] + a[0];
	
	sort(dis.begin(), dis.end());
	
	int ans = 0;
	for(int i = 0; i < n - 1; ++i) {
		ans += dis[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
