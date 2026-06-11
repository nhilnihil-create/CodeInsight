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
	
	vector<int> a(n), cnt(n, 0);
	for(int i = 0; i < n - 1; ++i) {
		cin >> a[i];
		a[i]--;
		cnt[a[i]]++;
	}
	
	for(int i = 0; i < n; ++i) {
		cout << cnt[i] << endl;
	}
	
	return 0;
}
