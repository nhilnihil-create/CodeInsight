#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	long long int i,n,p,x,c=0,k,q,j;
	cin>>n>>k>>q;
	int a[q],b[n];
	for(i=0;i<q;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		b[i]=k-q;
	for(i=0;i<q;i++)
		{
			b[a[i]-1]++;
		}
	
	for(i=0;i<n;i++)
		{
			if(b[i]>0)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
}