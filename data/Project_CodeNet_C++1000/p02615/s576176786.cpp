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
 long long int n,a[200002];
 scanf("%lld",&n);
 for(int i=0;i<n;i++)
 {
	scanf("%lld",&a[i]);
 }
 sort(a,a+n,greater<long long int>());
 long long int ans=0;
 for(int i=1;i<n;i++)
 {
	ans+=a[(i/2)];
 }
 printf("%lld",ans);
}