#include<iostream>
using namespace std;
int h,a[11][5];
main()
{
	while(cin>>h,h)
	{
		for(int i=0;i<h;i++)for(int j=0;j<5;j++)cin>>a[i][j];
		int ans=0;
		bool flag=1;
		while(flag)
		{
			flag=0;
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(a[i][j]&&a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2])
					{
						ans+=a[i][j]*3;
						flag=1;
						if(j+3<5&&a[i][j]==a[i][j+3])
						{
							ans+=a[i][j],a[i][j+3]=0;
							if(j+4<5&&a[i][j]==a[i][j+4])ans+=a[i][j],a[i][j+4]=0;
						}
						a[i][j]=a[i][j+1]=a[i][j+2]=0;
					}
				}
			}
			for(int j=0;j<5;j++)
			{
				for(int i=h;i-->0;)
				{
					if(a[i][j]==0)
					{
						int k;
						for(k=i-1;k>=0&&a[k][j]==0;k--);
						if(k<0)break;
						a[i][j]=a[k][j];
						a[k][j]=0;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}

