#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,c;

int main()
{
	
	scanf("%d%d%d",&a,&b,&c);
	if(b*c>=a)
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
	
}