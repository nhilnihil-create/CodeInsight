#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,i,j,x;
	cin>>n;
	for(i=n;;i++)
	{
		x=1;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				x=0;
				break;
			}
		}
		if(x==1)
		{
			cout<<i<<endl;
			return 0;
		}
		
		
	}
}