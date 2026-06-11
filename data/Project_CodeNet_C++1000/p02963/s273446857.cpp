#include<cstdio>
#include<cstring> 
#include<iostream>
using namespace std;
#define INF 1000000000
long long int a,b,c,d,s;
int main(){
scanf("%lld",&s);
if(s%INF)
printf("0 0 %lld %lld %lld %lld\n",1,s/INF+1,INF,INF-s%INF);
else 
printf("0 0 %lld %lld %lld %lld\n",1,s/INF,INF,0);
}