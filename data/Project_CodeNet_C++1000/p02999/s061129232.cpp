#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, a;
	scanf("%d %d", &x, &a);
	if (x < a)
	{
		printf("0\n");
	}
	else
	{
		printf("10\n");
	}
	return 0;
}