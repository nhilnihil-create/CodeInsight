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

#define MAXN 50000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, x, y, best, s, id;
	long double c, ans;
	vector<pair<long double, pair<long long, long long>>> plist;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		if ((x != 0) || (y != 0)) {
			c = atan2(y, x);
			plist.push_back({ c, {x, y} });
		}
	}
	n = plist.size();
	sort(plist.begin(), plist.end());

	best = 0;
	for (i = 0; i < n; i++) {
		x = 0; y = 0;
		for (j = 0; j < n; j++) {
			id = (i + j) % n;
			x += plist[id].second.first;
			y += plist[id].second.second;

			best = max(best, x * x + y * y);
		}
	}

	ans = sqrt(best * 1.0);
	cout << setprecision(20) << fixed << ans << "\n";

	return 0;
}
