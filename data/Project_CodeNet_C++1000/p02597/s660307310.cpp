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
 int n,wc=0;
 string c;
 scanf("%d",&n);
 cin >> c;
 for(int i=0;i<n;i++)
 {
	if(c[i]=='W'){wc++;}
 }
 int ans=0;
 for(int i=n-1;i>(n-1-wc);i--)
 {
	if(c[i]=='R'){ans++;}
 }
 printf("%d",ans);
}