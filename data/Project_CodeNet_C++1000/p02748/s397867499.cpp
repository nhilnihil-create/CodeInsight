#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b, m;
	scanf("%d %d %d", &a, &b, &m);
	vector<int> fri(a);
	vector<int> mic(b);
	vector<int> x(m);
	vector<int> y(m);
	vector<int> c(m);
	int dismin = 1e9;
	for(int i = 0; i < a; i++) {
		scanf("%d", &fri[i]);
	}
	for(int i = 0; i < b; i++) {
		scanf("%d", &mic[i]);
	}
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &x[i], &y[i], &c[i]);
	}
	for(int i = 0; i < m; i++) {
		int dis = 0;
		dis= fri[x[i] - 1] +  mic[y[i] - 1] - c[i];
		dismin = min(dismin, dis);
	}
	sort(fri.begin(), fri.end());
	sort(mic.begin(), mic.end());
	int ans;
	ans = min(dismin, fri[0] + mic[0]);
	printf("%d\n", ans);
}