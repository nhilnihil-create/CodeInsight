#include "stdio.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int aw,bw;
	for(int i = 0; i < 4; i++)
	{
		scanf("%d",&aw);
		a += aw;
	}
	for(int i = 0; i < 4; i++)
	{
		scanf("%d",&bw);
		b += bw;
	}
	printf("%d\n",max(a,b));
	return 0;
}