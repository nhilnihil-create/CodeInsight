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
#include <numeric>
#include <math.h> 

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, ans, carry, x;
	bool valid = true;

	cin >> n;
	vector<long long> a(n + 1), s(n + 2);
	for (i = 0; i <= n; i++) cin >> a[i];
	s[n + 1] = 0; 
	for (i = n; i >= 0; i--) s[i] = s[i + 1] + a[i];

	ans = 0;
	carry = 1;
	for (i = 0; i <= n; i++) {
		if (carry < a[i]) {
			valid = false;
			break;
		}
		
		carry -= a[i];
		carry = min(carry, s[i + 1]);

		ans += carry + a[i];

		carry *= 2;
	}

	if (!valid) ans = -1;
	cout << ans << "\n";

	return 0;
}

