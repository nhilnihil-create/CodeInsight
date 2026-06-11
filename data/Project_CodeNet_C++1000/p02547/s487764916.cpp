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
#include <complex>

using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k;
	bool found = false;

	cin >> n;
	vector<int> x(n), y(n);
	for (i = 0; i < n; i++) cin >> x[i] >> y[i];

	for (i = 2; i < n; i++) {
		if ((x[i - 2] == y[i - 2]) && (x[i - 1] == y[i - 1]) && (x[i] == y[i])) found = true;
	}
	if (found) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}


