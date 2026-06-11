#include<cstdio>
#include<cstring> 
#include<iostream>
#include<algorithm>
using namespace std;
const int M=1200000;
unsigned long long ans,d,c,sum;int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%llu%llu",&d,&c) ,sum+=c,ans+=d*c;
	
	printf("%llu",sum+(ans-1)/9-1);
		
}