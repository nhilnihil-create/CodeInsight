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

	string s, ans;
	cin >> s;
	int n = s.length(), i, j, k, x;
	vector<int> ad(n + 1, -10000000), ap(n + 1, -10000000), lastd(n + 1), lastp(n + 1);
	ad[0] = 0; 
	for (i = 0; i < n; i++) {
		if ((s[i] == 'D') || (s[i] == '?')) {
			if (ad[i] + 1 > ad[i + 1]) {
				ad[i + 1] = max(ad[i + 1], ad[i] + 1);
				lastd[i + 1] = 0;
			}
			if (ap[i] + 2 > ad[i + 1]) {
				ad[i + 1] = max(ad[i + 1], ap[i] + 2);
				lastd[i + 1] = 1;
			}
		}
		if ((s[i] == 'P') || (s[i] == '?')) {
			if (ad[i] > ap[i + 1]) {
				ap[i + 1] = max(ap[i + 1], ad[i]);
				lastp[i + 1] = 0;
			}
			if (ap[i] > ap[i + 1]) {
				ap[i + 1] = max(ap[i + 1], ap[i]);
				lastp[i + 1] = 1;
			}
		}
	}

	ans = s;
	if (ad[n] > ap[n]) x = 0;
	else x = 1;

	for (i = n - 1; i >= 0; i--) {
		if (x == 0) {
			ans[i] = 'D';
			x = lastd[i + 1];
		}
		else {
			ans[i] = 'P';
			x = lastp[i + 1];
		}
	}

	cout << ans << "\n";

	return 0;
}

