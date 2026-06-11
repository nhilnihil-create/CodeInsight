#include<iostream>
#include<algorithm>
#include<cmath>
#include<unordered_set>
#include<cstdio>

using namespace std;
typedef long long ll;
const int N = 1010;

int main()
{
	ll x, k, d;
	scanf("%lld%lld%lld", &x, &k, &d);
	
	
	ll t = abs(x) / d;
	
	if(k > t)
	{
		if(x > 0)	x -= t * d;
		else	x += t * d;
		if((k - t) & 1)
		{
			if(abs(x + d) < abs(x - d))	x += d;
			else	x -= d;
		}
	}
	else
	{
		if(x > 0)	x -= k * d;
		else	x += k * d;
	}
	
	printf("%lld\n", abs(x));
	
	return 0;
}