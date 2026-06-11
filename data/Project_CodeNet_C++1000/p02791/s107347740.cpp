#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n;
	cin>>n;
	long int i,j,p[n],x,s,t=n;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	s=p[0];
	for(i=1;i<n;i++)
	{
		if(p[i]>s)
		{
			t--;
		}
		if(s>p[i])
		{
			s=p[i];
		}
	}
	cout<<t<<endl;
}