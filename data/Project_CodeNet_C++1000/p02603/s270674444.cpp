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
 int n;
 long long int money=1000;
 long long int kabu;
 int a[200];
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
	 scanf("%d",&a[i]);
 }
 for(int i=1;i<n;i++)
 {
  kabu=money/a[i-1];
  money-=kabu*a[i-1];
  money+=kabu*max(a[i],a[i-1]);
 }
 printf("%lld",money);
}