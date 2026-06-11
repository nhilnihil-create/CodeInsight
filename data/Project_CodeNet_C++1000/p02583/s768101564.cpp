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
 int n,l[102],ans=0;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
	scanf("%d",&l[i]);
 }
 for(int i=0;i<n;i++)
 {
	for(int j=i+1;j<n;j++)
	{
		for(int k=j+1;k<n;k++)
		{
		 if(l[i]+l[j]>l[k]&&l[i]+l[k]>l[j]&&l[j]+l[k]>l[i]&&l[i]!=l[j]&&l[i]!=l[k]&&l[j]!=l[k]){ans++;}
		}
	}
 }
 printf("%d",ans);
}

