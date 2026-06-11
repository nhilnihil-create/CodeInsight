#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int res=0;
	scanf("%d",&n);
	if(n&1)
	{
		res=n/2;
	}
	else
	{
		res=n/2-1;
	}
	printf("%d",res);
}