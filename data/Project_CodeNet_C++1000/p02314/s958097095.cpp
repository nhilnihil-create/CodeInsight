#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

signed main() {
	int a, b;
	cin >> a >> b;
	int c[50001];
	for (int d = 0; d <= a; d++) {
		c[d] = 1 << 29;
	}
	vector<int>f(b);
	for (int e = 0; e < b; e++)cin >> f[e];
	c[0] = 0;
	for (int g = 1; g <= a; g++) {
		for (int h = 0; h < b; h++) {
			if (g >= f[h])c[g] = min(c[g], c[g - f[h]] + 1);
		}
	}
	printf("%d\n", c[a]);
}