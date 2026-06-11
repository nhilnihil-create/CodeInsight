#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	cin>>k;

	long long sum=0;

	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int p=1;p<=k;p++)
			{
				int x=__gcd(i,j);
				int y=__gcd(x,p);

				sum=sum+y;
			}
		}
	}	
	cout<<sum<<endl;

	return 0;
}