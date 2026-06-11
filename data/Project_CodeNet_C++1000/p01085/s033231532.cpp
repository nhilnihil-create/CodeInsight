#include<iostream>
using namespace std;
int m,n1,n2;
main()
{
	while(cin>>m>>n1>>n2,m)
	{
		int p[222],ansg=0,ansi;
		for(int i=0;i<m;i++)cin>>p[i];
		for(int i=n2;i>=n1;i--)
		{
			if(ansg<p[i-1]-p[i])
			{
				ansg=p[i-1]-p[i];
				ansi=i;
			}
		}
		cout<<ansi<<endl;
	}
}

