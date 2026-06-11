#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
	long long int n,i,a[3][3];
	int f=0,colsum=0,rowsum=0,k,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>a[i][j];
	cin>>n;
	int b[n];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(k=0;k<n;k++)
		{
			for(i=0;i<3;i++)
				{
					rowsum=0;
					for(j=0;j<3;j++)
						{
							if(a[i][j]==b[k])
								a[i][j]=-1;
								rowsum+=a[i][j];
						}
					if(rowsum==-3)
					{
						f=1;
						break;
					}
				}
		}

for(k=0;k<n;k++)
		{
			for(j=0;j<3;j++)
				{
					colsum=0;
					for(i=0;i<3;i++)
						{
							if(a[i][j]==b[k])
								a[i][j]=-1;
								colsum+=a[i][j];
						}
					if(colsum==-3)
					{
						f=1;
						break;
					}
				}
		}
	if(a[0][0]+a[1][1]+a[2][2]==-3)
		f=1;
		
	if(a[0][2]+a[1][1]+a[2][0]==-3)
		f=1;
	if(f==1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
		
}