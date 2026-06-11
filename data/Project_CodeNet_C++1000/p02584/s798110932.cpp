#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll x,k,d;
	cin>>x>>k>>d;
	x=abs(x);
	ll p=min(k,x/d);
		
	k-=p;
	x-=p*d;
	if(k%2==0)
		cout<<x;
	else
		cout<<d-x;
	return 0;
	
}