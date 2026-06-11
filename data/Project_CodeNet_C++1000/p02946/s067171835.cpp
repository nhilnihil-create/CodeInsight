#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k, x;
	scanf("%d%d", &k, &x);
	for (int i = x - k + 1; i <= x + k - 1; i++) {
		printf("%d\n", i);
	}
	return 0;
}