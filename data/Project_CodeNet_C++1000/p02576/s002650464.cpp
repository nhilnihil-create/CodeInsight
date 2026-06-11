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
int n,x,t;
scanf("%d %d %d",&n,&x,&t);
int ans;
ans=n/x;
if(n%x!=0){ans++;}
ans=ans*t;
printf("%d",ans);
}
