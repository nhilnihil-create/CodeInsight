#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int p, q, r;
	scanf("%d %d %d", &p, &q, &r);
	printf("%d\n", p + q + r - max({p, q, r}));
	return 0;
}