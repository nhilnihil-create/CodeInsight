#include <bits/stdc++.h>
using namespace std;

int n, m;

signed main () {
	scanf("%d %d", &n, &m);
	vector < pair < int, int > > ans;
	if (n % 2) {
		for (int a = 1, b = n; a < b; a++, b--) 
			ans.push_back(make_pair(a, b));
	} 
	else {
		for (int a = 1, b = n / 2; a < b; a++, b--) 
            ans.push_back(make_pair(a, b));
		for (int a = n / 2 + 1, b = n - 1; a < b; a++, b--) 
			ans.push_back(make_pair(a, b));
	}
	for (int i = 0; i < m; ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
}
