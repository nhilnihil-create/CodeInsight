#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;

int main()
{
 long long int N,ans;
 scanf("%lld",&N);
 if(N%2!=0){ans=0;}
 else{
 ans=N/10;
 N/=10;
 for(int i=1;;i++)
 {
	ans+=(N/5);
	N/=5;
	if(N==0){break;}
 }
 }
 printf("%lld",ans);
}

