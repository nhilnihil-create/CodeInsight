#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k,q;
	cin>>n>>k>>q;
	int a[n+1];
	for(int i=1;i<=n;i++)
	a[i]=0;
	for(int i=1;i<=q;i++)
	{
		int o;
		cin>>o;
		a[o]++;
	}
	long long s=q;
	for(int i=1;i<=n;i++)
	{
		if((s-a[i])<k)
		{
			cout<<"Yes"<<endl;
		}
		else
		cout<<"No"<<endl;
	}
 } 