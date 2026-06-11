#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	long long int i,n,p=0,j;
	cin>>n;
	int h[n];
	for(i=0;i<n;i++)
		cin>>h[i];
	if(n==1)
		{
			cout<<"Yes"<<endl;
		}
		
	else
	{
	
		for(i=1;i<n;i++)
		{
			if(h[i]>h[i-1])
				h[i]-=1;
		
		}
		for(i=1;i<n;i++)
			{
				if(h[i]<h[i-1])
					{
						p=1;
						break;
					}
			}
		if(p==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}