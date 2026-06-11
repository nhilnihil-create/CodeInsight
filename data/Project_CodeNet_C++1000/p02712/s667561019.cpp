#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long
using namespace std;
//bool cmp(int x,int y)
//{
//	return x>y;
//}
//int a[1005];
//int flag1=0;
int main()
{
  int n;
cin>>n;
ll sum=0;
for(int i=1;i<=n;i++)
{
	if(i%3==0||i%5==0)
	continue;
	else
	
	sum+=i;
}
   printf("%lld\n",sum);
   return 0;
}