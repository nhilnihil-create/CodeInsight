#include<iostream>
#include<cstdio>
using namespace std;
long long f[10000000];
int main()
{
	int i,n;
	for(i=1;i<=1000000;i++)
	{
		if(i%3==0||i%5==0)
			f[i] = f[i-1];
		else
			f[i] = f[i-1] + i;
	}
	cin>>n;
	cout<<f[n];
	return 0;
}