#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", n * 360 / __gcd(n, 360) / n);
	return 0;
}