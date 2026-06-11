#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 100005
using namespace std;
typedef long long ll;
ll fac[maxn];
ll sum[maxn];
int st[maxn];

int main()
{
	int top=0;
	ll n;
	cin>>n;
	while(n)
	{
		if(n%26==0)
			st[++top]=26,n/=26,n--;
		else
			st[++top]=n%26,n/=26;
	}
	for(int i=top;i>=1;i--)
		printf("%c",st[i]+'a'-1);
	printf("\n");
}