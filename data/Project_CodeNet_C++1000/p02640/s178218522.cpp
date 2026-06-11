#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int x,y,a,b;
int main()
{
	cin>>x>>y;
	for (a=0;a<=x;++a)
	{
		b=x-a;
		if (a*2+b*4==y)
		{
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}