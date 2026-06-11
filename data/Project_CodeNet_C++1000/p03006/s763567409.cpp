#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
map<pii, int>Map;
int n, res;
pii w[60];
int main() {
	int i, j, k;
	scanf("%d", &n);
	res = n;
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].first, &w[i].second);
		Map[w[i]] = 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j)continue;
			int x = w[j].first - w[i].first, y = w[j].second - w[i].second;
			int c = 0;
			for (k = 1; k <= n; k++) {
				if (Map.count({ w[k].first + x,w[k].second + y }))c++;
			}
			res = min(res, n - c);
		}
	}
	printf("%d\n", res);
	return 0;
}