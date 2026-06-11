#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,asum=0,bsum=0;
	for(int i=0;i<4;i++)
	{
		cin>>a;
		asum+=a;
	}
	for(int i=0;i<4;i++)
	{
		cin>>b;
		bsum+=b;
	}
	if(asum>=bsum)
		cout<<asum<<endl;
	else
		cout<<bsum<<endl;
	return 0;
}
