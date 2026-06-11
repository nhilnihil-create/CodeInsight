#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void)
{
	ll n,c=1;
	string s;
	cin>>n;
	cin>>s;
	for(ll i=0;i<n-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			c++;
		}
	}
	cout<<c<<endl;
}