#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 200005
using namespace std;
typedef long long ll;
int n;
int a[maxn];
int main()
{
	scanf("%d",&n);
	int temp=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),temp^=a[i];
	if(n&1)
	{
		for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
	else
	{
		for(int i=1;i<=n;i++)
		printf("%d ",a[i]^temp);
		printf("\n");
	}
}