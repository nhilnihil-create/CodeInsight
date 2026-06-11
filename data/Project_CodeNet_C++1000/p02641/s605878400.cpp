#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,d=0,e=0;
	cin>>a>>b;
	int c[b+1];
	for(int i=1;i<=b;i++)
	cin>>c[i];
	for(int i=0;i<=b;i++)
	{
		d=0;
		e=0;
		for(int k=1;k<=b;k++)
		{
			if(a+i==c[k])
			{
				d++;
 			}
			if(a-i==c[k])
			{
				e++;
			}
		}
		if(e==0)
		{ 
			cout<<a-i<<endl;
			return 0; 
		} 
		if(d==0)
		{
			cout<<a+i<<endl;
			return 0;
		}
	}
}
