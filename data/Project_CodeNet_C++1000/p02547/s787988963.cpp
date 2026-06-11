#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll n;
	cin>>n;
	ll d[n][2];
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<2;j++)
		cin>>d[i][j];
	}
	ll f=0;
	for(ll i=0;i<n-2;i++)
	{
		if(d[i][0]==d[i][1]&&d[i+1][0]==d[i+1][1]&&d[i+2][0]==d[i+2][1])
		{
		f=1;
		break;
		}
	}
	if(f)
	cout<<"Yes"<<"\n";
	else
	cout<<"No"<<"\n";
	

	return 0;
}