#include <bits/stdc++.h>
using namespace std;

int f[100010];
int r[100010];

int main(){
	int a, b, m;
	scanf("%d%d%d", &a, &b, &m);
	for(int i = 0; i < a; i++)
		scanf("%d", f + i);
	for(int i = 0; i < b; i++)
		scanf("%d", r + i);
	long ans = *min_element(f, f + a) + *min_element(r, r + b);
	for(int i = 0; i < m; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		ans = min(ans, (long)f[x-1] + r[y-1] - c);
	}
	printf("%ld\n", ans);
}
