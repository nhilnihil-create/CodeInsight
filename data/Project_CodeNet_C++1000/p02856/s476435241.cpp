#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;

int main()
{
	// freopen("input.in", "r", stdin);

	int n; scanf("%d", &n);

	long sum = 0, dig = 0;
	for(int i = 0; i < n; i++)
	{
		long a, b;
		scanf("%lld %lld", &a, &b);
		sum += b*a;
		dig += b;
	}
	long res = 0;
	while(dig != 1)
	{
		res += dig-1;
		dig = 1 + sum/10;
		sum = sum%10 + sum/10;
	}
	printf("%lld\n", res);
}