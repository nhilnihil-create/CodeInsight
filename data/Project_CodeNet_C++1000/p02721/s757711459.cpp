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

	int n, k, c, i, j, ans, last, ct;
	string s;
	cin >> n >> k >> c >> s;
	vector<int> ll(n, -1), rr(n, -1);
	
	ct = 0; last = -n - n;
	for (i = 0; i < n; i++) {
		if ((ct <= k) && (s[i] == 'o') && (i - last >= c + 1)) {
			ll[i] = ct++;
			last = i;
		}
	}

	ct = 0; last = n * 3;
	for (i = n - 1; i >= 0; i--) {
		if ((ct <= k) && (s[i] == 'o') && (last - i >= c + 1)) {
			rr[i] = k - 1 - ct;
			ct++;
			last = i;
		}
	}

	for (i = 0; i < n; i++) {
		if ((ll[i] == rr[i]) && (ll[i] != -1)) cout << i + 1 << "\n";
	}

	return 0;
}


