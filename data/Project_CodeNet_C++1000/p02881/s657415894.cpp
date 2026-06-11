#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
#define PI 3.1415927
int main()
{
	long long i,j,n,ans=0;
	cin>>n;
	for(i=sqrt(n);i>=1;i--)
	{
		j = n / i;
		if(i*j==n)
		{
			ans = i + j -2;
			break;
		}
	}
	cout<<ans;
	return 0;
}