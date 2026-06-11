#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
	ll n,k,c,i;
	cin>>n>>k>>c;
	string st;
	cin>>st;
	int L[k],R[k];
	int z=0;
	for(i=0;i<n;i++)
	{
		if(st[i]=='o'&&z<k)
		{
		L[z++]=i;
		i+=c;
		}
	}
	z=k-1;
	for(i=n-1;i>=0;i--)
	{
		if(st[i]=='o'&&z>=0)
		{
		R[z--]=i;
		i-=c;
		}
	}
	for(i=0;i<k;i++)
	{
		//cout<<L[i]<<" "<<R[i]<<endl;
		
		if(L[i]==R[i])
		cout<<L[i]+1<<endl;
		
	}
	return 0;
}
