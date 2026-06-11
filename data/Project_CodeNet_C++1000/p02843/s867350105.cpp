#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll x;
	cin >> x;
	ll y = x%100;
	ll z = (y+4)/5;
	if(x/100>=z)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
}