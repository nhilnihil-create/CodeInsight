#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,d,s;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	s=max(a*c,b*d);
	s=max(s,a*d);
	s=max(s,b*c);
	cout<<s;
	return 0;
}