#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			s++;
			if(s==3)
			{
				puts("Yes");
				return 0;
			}
		}
		else
			s=0;
	}
	puts("No");
	return 0;
}