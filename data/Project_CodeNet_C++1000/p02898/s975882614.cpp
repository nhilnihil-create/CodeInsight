#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = 0;
	rep(i, n) {
		int h;
		scanf("%d", &h);
		if(h >= k) ans++;
	}
	printf("%d\n", ans);
	return 0;
}