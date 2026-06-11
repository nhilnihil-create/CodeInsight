#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main() {
	long long int n, k;
	cin >> n >> k;
	long long int suma[200001] = {};
	for (int i = 1; i <= n; i++) {
		long long int a;
		cin >> a;
		suma[i] = (a + suma[i - 1]) % k;
	}
	if (k == 1) {
		cout << 0 << endl;
		return 0;
	}
	map<int, int> cnt;
	long long int sum = 0;
	long long int ans = 0;
	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		int a;
		long long int tmp = (suma[i] - (i % k) + k) % k;
		if (cnt.find(tmp) != cnt.end()) {
			ans += cnt[tmp];
			cnt[tmp]++;
		} else {
			cnt[tmp] = 1;
		}
		if (i >= k - 1) {
			tmp = (suma[i - k + 1] - ((i - k + 1) % k) + k) % k;
			cnt[tmp]--;
		}
		// cout << ans << endl;
	}
	cout << ans << endl;
}