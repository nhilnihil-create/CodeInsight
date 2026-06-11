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

	int n, i, j, k, nn, x;
	cin >> n;

	vector<pair<int, int>> ans;

	nn = n;
	while (nn % 2 == 0) nn /= 2;
	if (nn == 1) cout << "No\n";
	else {
		// build chain of 1 to 3
		ans.push_back({ 1, 2 });
		ans.push_back({ 2, 3 });
		ans.push_back({ 3, n + 1 });
		ans.push_back({ n + 1, n + 2 });
		ans.push_back({ n + 2, n + 3 });

		for (i = 4; i < n; i += 2) {
			ans.push_back({ i, n + 1 });
			ans.push_back({ i, n + i + 1 });
			ans.push_back({ i + 1, n + 1 });
			ans.push_back({ n + i, i + 1 });
		}

		if (n % 2 == 0) {
			// find the last 1-bit of n
			x = 1;
			while (!(x & n)) x *= 2;

			ans.push_back({ x + 1, n });
			ans.push_back({ n - x, n + n });
		}

		cout << "Yes\n";
		for (auto p : ans) cout << p.first << " " << p.second << "\n";
	}



	return 0;
}

