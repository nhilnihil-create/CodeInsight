#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>


using namespace std;


int main()
{
	int x;
	int ans;
	long long sum=360;
	scanf("%d",&x);
	if(sum%x==0)ans=sum/x;
	else
	{
		for(int i=1;;i++)
		{
			sum=i*360;
			if(sum%x==0)
			{
				ans=sum/x;
				break;
			}
		}
	}
	printf("%d",ans);
}