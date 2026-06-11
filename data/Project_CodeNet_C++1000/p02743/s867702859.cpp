#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll a,b,c;
	cin >> a >> b >> c;
	if(c-b-a<=0)
	{
		cout<<"No"<<endl;
	}
	else
	{	
		if(4*a*b<(c-b-a)*(c-b-a))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}