#include<bits/stdc++.h>
using namespace std;
int a,b,c,k;
int main()
{
	cin>>a>>b>>c>>k;
	while(a>=b)
	{
		if(k==0)
		{
			cout<<"No";
			return 0;
		}
		k--;
		b*=2;
	}
	while(b>=c)
	{
		if(k==0)
		{
			cout<<"No";
			return 0;
		}
		k--;
		c*=2;
	}
	cout<<"Yes";
	return 0;
}