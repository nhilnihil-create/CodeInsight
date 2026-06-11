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
int a,b;
int ren=0;
int flag=0;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%d %d",&a,&b);
if(a==b){ren++;}
else{ren=0;}
if(ren==3){flag=1;}
}
if(flag==1){printf("Yes");}
else{printf("No");}
}
