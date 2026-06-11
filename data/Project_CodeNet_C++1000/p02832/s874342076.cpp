#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n;
	cin>>n;
	long int i,j,a[n],t=0,x=1,s=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(j=0;j<n;j++)
	{	
			if(x==a[j])
			{
				x++;
			}
			else
			{
				s++;
			}
			
	}
	if(x==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<s<<endl;
}