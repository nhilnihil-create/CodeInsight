#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int i,s[m],c[m],a[n]={1},d=0;
	for(i=0;i<m;i++)
	{
		cin>>s[i]>>c[i];
		a[s[i]-1]=c[i];
		
	}
	for(i=0;i<m;i++)
	{
		for(int j=i;j<m;j++)
		{
			if(s[i]==s[j])
			{
				if(c[i]!=c[j])
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
	d=d+a[i]*pow(10,n-i-1);
	}
	int t=d/(pow(10,n-1));
	if(m==0 && n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(t>0 || (n==1 && c[0]==0))
	{
		cout<<d;
	}
	else
	{
		cout<<-1<<endl;
	}
	
}