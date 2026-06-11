#include <bits/stdc++.h>
#define int long long
using namespace std;
int x;
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
signed main()
{
	scanf("%lld",&x);
	int sum=lcm(x,360);
	printf("%lld\n",sum/x);
}