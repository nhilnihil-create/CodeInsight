#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int x;
int main()
{
	cin>>x;
	for (int i=1;i<=10000;++i)
	{
		if ((x*i)%360==0)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
    return 0;
}