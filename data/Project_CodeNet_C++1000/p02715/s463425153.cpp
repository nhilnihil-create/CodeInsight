#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, k, i, j, x, ans = 0, MOD = 1000000007, p, MAXLEVEL = 30;

	cin >> n >> k;
	vector<long long> s(k + 1, 0);
	for (i = k; i >= 1; i--) {
		x = k / i;
		// calculate x ^ n
		p = 1;
		for (j = 0; j < MAXLEVEL; j++) {
			if ((1LL << j) & n) p = (p * x) % MOD;
			x = (x * x) % MOD;
		}

		// minus s[2i, 3i, ...]
		p += MOD * MOD;
		for (j = 2 * i; j <= k; j += i) p -= s[j];
		s[i] = p % MOD;

		ans = (ans + i * s[i]) % MOD;
	}
	cout << ans << "\n";


	return 0;
}
