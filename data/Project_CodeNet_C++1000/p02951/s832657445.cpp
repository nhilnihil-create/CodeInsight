#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = c - (a - b);
	if(ans > 0) printf("%d\n", ans);
	else printf("0\n");
	return 0;
}