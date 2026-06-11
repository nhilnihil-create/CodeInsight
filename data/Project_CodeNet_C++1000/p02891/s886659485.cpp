#include<bits/stdc++.h>
using namespace std;

char s[101010];

int a[101010];

int main()
{
	scanf("%s", s);
	int k;
	scanf("%d", &k);
	int len = strlen(s);
	
	int n = 0;
	for(int i = 0; i < len; i++)
	{
		if(i == 0 || s[i] != s[i-1])
		{
			n++;
			a[n] = 1;
		}
		else
			a[n]++;
	}
	if(n == 1)
	{
		printf("%lld\n", 1ll * len * k / 2);
		return 0; 
	}
	int sum = 0;
	for(int i = 2; i < n; i++)
		sum += a[i]/2;
	if(s[0] != s[len - 1])
		sum += a[1]/2 + a[n]/2;
	else
		sum += (a[1] + a[n])/2;
	printf("%lld\n", 1ll * sum * k - (s[0] == s[len - 1]) * ((a[1] + a[n])/2 - a[1]/2 - a[n]/2));
	return 0;
}