#include<iostream>
using namespace std;
int n;
main()
{
	while(cin>>n,n)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				cnt+=k*(k+1)/2-j*(j-1)/2==n;
			}
		}
		cout<<cnt<<endl;
	}
}

