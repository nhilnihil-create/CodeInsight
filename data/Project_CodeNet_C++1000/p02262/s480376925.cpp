#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1111111], c, g[20];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	g[0] = 1; c = 0;
	while(true) {
		g[c + 1] = g[c] * 3 + 1;
		if(g[++c] >= n) break;
	}
	int ret = 0;
	for(int i = c - 1; i >= 0; i--) {
		for(int j = g[i]; j < n; j++) {
			int v = a[j], w = j - g[i];
			while(w >= 0 && a[w] > v) {
				a[w + g[i]] = a[w];
				w -= g[i];
				ret++;
			}
			a[w + g[i]] = v;
		}
	}
	printf("%d\n", c);
	for(int i = c - 1; i >= 0; i--) printf(i ? "%d " : "%d\n", g[i]);
	printf("%d\n", ret);
	for(int i = 0; i < n; i++) printf("%d\n", a[i]);
	return 0;
}