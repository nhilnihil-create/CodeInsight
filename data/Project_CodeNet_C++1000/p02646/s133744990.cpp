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

	long long a, b, v, w, t, x, d;
	cin >> a >> v >> b >> w >> t;

	d = abs(a - b);
	bool valid;

	if (d == 0) valid = true;
	else if (w >= v) valid = false;
	else {
		x = (v - w) * t;
		valid = x >= d;
	}

	if (valid) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
