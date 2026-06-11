#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const LL m=(LL)1000000000*1000000000;
int n;
int main(){
	//int T;  cin>>T;
	int T=1;
	while(T --> 0){
		scanf("%d",&n);
		LL x;
		LL bwl=1;
		while(n --> 0){
			scanf("%lld",&x);
			if(x==0){
				bwl=0;
				break;
			}
			if(bwl!=-1){
				if(m/bwl<x){
					bwl=-1;
				}
				else{
					bwl=bwl*x;
				}
			}
		}
		printf("%lld\n",bwl);
	}
	return 0;
}


