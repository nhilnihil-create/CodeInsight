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

	int n, i, j, k, x;
	bool valid = true;
	cin >> n;
	map<int, int> ct;
	map<int, int>::iterator it;
	for (i = 0; i < (1 << n); i++) {
		cin >> x;
		ct[x]++;
	}
	vector<int> a;
	a.push_back(ct.rbegin()->first);
	ct[a[0]]--;
	if (ct[a[0]] == 0) ct.erase(a[0]);

	for (i = 1; i <= n; i++) {
		for (j = 0; j < (1 << (i - 1)); j++) {
			it = ct.lower_bound(a[j]);
			if (it == ct.begin()) {
				valid = false; break;
			}
			it--;
			x = it->first;
			a.push_back(x);
			if (--ct[x] == 0) ct.erase(x);
		}
	}

	if (valid) cout << "Yes\n"; 
	else cout << "No\n";

	return 0;
}
