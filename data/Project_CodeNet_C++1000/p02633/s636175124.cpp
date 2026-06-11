#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	scanf("%d", &x);
	int k = 1;
	while (k * x % 360 != 0) k++;
	printf("%d\n", k);
	return 0;
}