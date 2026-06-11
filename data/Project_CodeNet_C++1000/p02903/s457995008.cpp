#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	for(int i=1;i<=h;i++){for(int j=1;j<=w;j++)
	{
		if((j>a&&i<=b)||(i>b&&j<=a)) putchar('1');
		else putchar('0');
	}putchar('\n');}
}