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

	long long n, m, sum, i, j, k, d, c, ans;
	cin >> m;
	n = 0; sum = 0;
	while (m--) {
		cin >> d >> c;
		n += c;
		sum += c * d;
	}

	ans = n + (sum - 1) / 9 - 1;
	cout << ans << "\n";

	return 0;
}

