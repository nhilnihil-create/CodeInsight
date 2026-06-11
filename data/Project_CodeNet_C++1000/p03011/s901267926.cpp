#include <bits/stdc++.h>
using namespace std;
int main()
{
	int p, q, r;
	scanf("%d%d%d", &p, &q, &r);
	int maxn = max({p, q, r});
	printf("%d\n", p + q + r - maxn);
	return 0;
}