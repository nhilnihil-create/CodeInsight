#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,d,i=0;
	cin>>n>>d;
	while(n--)
	{
		double a,b;
		cin>>a>>b;
		double x = (a*a)+(b*b);
		double y = sqrt(x);
		ll ans = ceil(y);
		if(ans<=d)
		{
			i++;
		}
	}
	cout<<i<<endl;
	return 0;
}