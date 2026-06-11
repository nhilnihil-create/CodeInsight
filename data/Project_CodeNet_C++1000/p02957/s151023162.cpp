#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll a,b;
	cin>>a>>b;
	ll c = a+b;
	if(c%2==0)
	{
		cout<<c/2<<endl;
	}
	else
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}