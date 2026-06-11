#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main()
{
int n;
long long int a[200005],s[200005];
scanf("%d",&n);
s[0]=0;
long long int z=0,x,ans=0;
for(int i=1;i<=n;i++)
{
	scanf("%lld",&a[i]);
	s[i]=max(s[i-1],a[i]);//s[i]はi人目までの高さの最大値
	x=max(z,s[i-1]-a[i]);
	ans+=x;
}
printf("%lld",ans);

}
