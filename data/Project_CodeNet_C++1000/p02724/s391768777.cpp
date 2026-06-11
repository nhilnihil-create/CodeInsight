#include<bits/stdc++.h>
using namespace std;

long long x,ans;

int main()
{
	scanf("%lld",&x);
	ans=(x/500)*1000ll;
	x%=500;
	ans+=x-x%5;
	printf("%lld\n",ans);
	return 0;
}