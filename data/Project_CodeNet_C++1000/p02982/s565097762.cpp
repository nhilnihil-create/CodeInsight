#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,d;
	cin>>n>>d;
	int i,j,k,x[n][d],z,b=0;
	double y[n][d],s;
	for(i=0;i<n;i++)
	{
		for(j=0;j<d;j++)
		{
			cin>>x[i][j];	
		}	
	}	
	for(i=0;i<n;i++)
	{
		for(k=i+1;k<n;k++)
		{
			z=0;
			s=0;
			for(j=0;j<d;j++)
			{
				y[i][j]=x[i][j]-x[k][j];
				y[i][j]=y[i][j]*y[i][j];
				s=s+y[i][j];
			}
			z=sqrt(s);
			s=sqrt(s);
			
			if(s==z)
			{
				b++;
			}
		}		
	}
	cout<<b<<endl;
	
}