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

	long long n, i, j, k, id, x, ct, iid, ans;
	cin >> n;
	vector<long long> a(n), b(n);
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) cin >> b[i];

	set<long long> s;
	for (i = 0; i < n; i++) {
		if ((b[i] > b[(i + 1) % n]) && (b[i] > b[(i + n - 1) % n]) && (b[i] > a[i])) s.insert(i);
	}

	ans = 0;
	while (!s.empty()) {
		id = *s.begin();
		s.erase(id);

		x = b[(id + 1) % n] + b[(id + n - 1) % n];
		ct = (b[id] - a[id]) / x;
		b[id] -= ct * x;
		ans += ct;

		i = (id + 1) % n;
		if ((b[i] > b[(i + 1) % n]) && (b[i] > b[(i + n - 1) % n]) && (b[i] > a[i])) s.insert(i);

		i = (id + n - 1) % n;
		if ((b[i] > b[(i + 1) % n]) && (b[i] > b[(i + n - 1) % n]) && (b[i] > a[i])) s.insert(i);
	}

	if (a == b) cout << ans << "\n";
	else cout << "-1\n";

	return 0;
}
