#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int main()
{
long long int n,d,x,y,ans=0;
scanf("%lld %lld",&n,&d);
for(int i=0;i<n;i++)
{
 scanf("%lld %lld",&x,&y);
 if((x*x+y*y)<=d*d){ans++;}
}
printf("%d",ans);
}