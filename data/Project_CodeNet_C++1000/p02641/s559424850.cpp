#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,d=0,e=0;
	cin>>x>>y;
	int c[y+1];
	for(int i=1;i<=y;i++)
	cin>>c[i];
	for(int i=0;i<=y;i++)
	{
		d=0;
		e=0;
		for(int k=1;k<=y;k++)
		{
			if(x+i==c[k])
			{
				d++;
 			}
			if(x-i==c[k])
			{
				e++;
			}
		}
		if(e==0)
		{ 
			cout<<x-i<<endl;
			return 0; 
		} 
		if(d==0)
		{
			cout<<x+i<<endl;
			return 0;
		}
	}
}