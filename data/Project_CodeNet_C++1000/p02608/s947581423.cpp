#include<iostream>
#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int main()
{
	ll n;
	cin >> n;
	ll i,j,k,a[n+1]={0};
	ll x=1,y=1,z=1;
	ll eq;
	for(x=1;x<sqrt(n);x++)
	{
		for(y=1;y<sqrt(n);y++)
		{
			for(z=1;z<sqrt(n);z++)
			{
				eq = pow(x,2) + pow(y,2) + pow(z,2) + x*y + y*z + z*x;
				if(eq<=n)
				{
					a[eq]++;	
				}	
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		cout << a[i] << endl;
	}
}