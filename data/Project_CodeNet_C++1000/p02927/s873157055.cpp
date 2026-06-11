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

	int m, d, i, j, k, ans, d1, d10;
	cin >> m >> d;
	ans = 0;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= d; j++) {
			d10 = j / 10;
			d1 = j % 10;

			if ((d1 >= 2) && (d10 >= 2) && (d1 * d10 == i)) {
				ans++;
				//cout << i << " " << j << "\n";
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

