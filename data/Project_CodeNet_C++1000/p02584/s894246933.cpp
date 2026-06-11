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
 long long int x,k,d,ans;
 scanf("%lld %lld %lld",&x,&k,&d);
 if(x<0){x=x*-1;}//反転してxを正の位置に
 long long int mim=x/d; //正の最近傍へ移動するための必要移動回数
 if(k<=mim){ans=x-d*k;}
else
 {
	long long int mmp=x-d*mim,mmm=x-d*mim-d;
	k=k-mim;
	if(k%2==0){ans=mmp;}
	else{ans=mmm;}
 }
 if(ans<0){ans=ans*-1;}
 printf("%lld",ans);
}

