#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int main()
{
	n=5;
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		if (x==0)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
	return 0;
}