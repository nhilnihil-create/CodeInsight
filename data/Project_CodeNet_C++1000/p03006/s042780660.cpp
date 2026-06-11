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

	int n, i, j, k, ans, x, y, ct, c, d, z;
	cin >> n;
	vector<pair<int, int>> a(n);
	set<pair<int, int>> s;
	for (i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		s.insert(a[i]);
	}

	ans = n;
	sort(a.begin(), a.end());
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			x = a[i].first - a[j].first;
			for (c = 0; c < n; c++) {
				for (d = c + 1; d < n; d++) {
					y = a[c].second - a[d].second;
					if ((x == 0) && (y == 0)) continue;

					ct = 0;
					for (z = 0; z < n; z++) {
						if (s.find({ a[z].first - x, a[z].second - y }) != s.end()) ct++;
					}
					ans = min(ans, n - ct);
				}
			}
		}
	}
	cout << ans << "\n";




	return 0;
}
