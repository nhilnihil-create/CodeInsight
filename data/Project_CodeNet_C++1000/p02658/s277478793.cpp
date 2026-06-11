#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
	ll a,z = 1;
	cin>>a;
	ll ar[a];
	for(ll i = 0; i<a; i++)
	{
		cin>>ar[i];
		if (ar[i] == 0)
		{
			cout<<0<<endl;
			exit(0);
		}
		
	}
	for (ll i = 0; i<a; i++)
	{

		if(z>1000000000000000000/ar[i])
		{
			cout<<-1<<endl;
			exit(0);
		}
		z*=ar[i];
	}
	cout<<z<<endl;
	return 0;
}