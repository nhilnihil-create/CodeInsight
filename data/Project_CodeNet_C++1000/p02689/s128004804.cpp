#include <bits/stdc++.h>

using namespace std;

int h[100005];
vector <int> edge[100005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	int res = 0;
	
	for (int i = 0; i < n; i++) {
		bool flag = 1;
		
		for (int j = 0; j < edge[i].size(); j++) {
			if (h[i] <= h[edge[i][j]]) flag = 0;
		}
		if (flag) res++;
	}
	
	printf("%d\n", res);
}
