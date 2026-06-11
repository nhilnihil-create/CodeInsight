#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int k;
	cin>>k;
	ll sum=0;
	for(int i=1; i<=k; i++)
	{
		for(int j=1; j<=k; j++)
		{
			for(int x=1; x<=k; x++)
			{
				int num1=__gcd(i,j);
				num1=__gcd(num1,x);
				sum+=num1;
			}
		}
	}
	cout<<sum;
	return 0;	
}