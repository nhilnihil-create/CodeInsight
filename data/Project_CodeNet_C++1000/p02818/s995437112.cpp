#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
	ll a,b,k;
	cin>>a>>b>>k;
	if(a+b<=k)
	{
		cout<<"0"<<" "<<"0";
	}
	else if(k>=a)
	{
		k = k-a;
		a = 0;
		b = abs(k-b);
		cout<<"0"<<" "<<b;
	}
	else
	{
		a = a-k;
		cout<<a<<" "<<b;
	}
	return 0;
}