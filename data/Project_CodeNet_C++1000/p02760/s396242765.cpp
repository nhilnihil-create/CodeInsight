#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3][3],i,j,x=0,y=0,z=0,r=0,s=0,t=0,g=0,h=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	int n;
	cin>>n;
	int b[n];
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(a[i][j]==b[k])
				{
					int u,v;
					u=i+1;
					v=j+1;
					if(u==v)
					{
						x++;
					}
					if(u+v==4)
					{
						y++;
					}
					if(u==1)
					{
						z++;
					}
					if(u==2)
					{
						r++;
					}
					if(u==3)
					{
						s++;
					}
					if(v==1)
					{
						t++;
					}
					if(v==2)
					{
						g++;
					}
					if(v==3)
					{
						h++;
					}
					
				}
			}
		}
	}

if(x==3 || y==3 || z==3 || r==3 || s==3 || t==3 || g==3 || h==3)
{
	cout<<"Yes"<<endl;
}
else
{
	cout<<"No"<<endl;
}

}