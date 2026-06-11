#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,j,s=0,x=0,h[n];
	for(i=0;i<n;i++)
	{
		cin>>h[i];
		
	}
	for(i=n-1;i>0;i--)
	{
		if(h[i-1]>=h[i])
		{
			x++;
		}
		else
		{
			if(x>=s)
			{
				s=x;
			}
			x=0;
			
		}
		
	}
	if(x>=s)
	{
		s=x;
	}
	cout<<s<<endl;
	
}