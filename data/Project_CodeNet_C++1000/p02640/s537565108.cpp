#include<cstdio>
#include<iostream>
using namespace std;
int x,y;
int main(void)
{
	while(cin>>x>>y)
	{
//	2m+4n=y;
//	m+n=x; 4m+4n=4x
//	n=(y-x)/2; m=x-(y-x)/2;
int fg=1;
	for(int i=0;i<=x;++i)
	{
		if(2*i+4*(x-i)==y)
		{
			puts("Yes");
			fg=0;
			break;
		}
	}
	if(fg)
	puts("No");
	}
	return 0;
}