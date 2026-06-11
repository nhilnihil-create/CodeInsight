#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	// (a + (b - 1)) / b 切り上げ
	int ans = (n + d * 2) / (2 * d + 1);
	printf("%d\n", ans);
	return 0;
}