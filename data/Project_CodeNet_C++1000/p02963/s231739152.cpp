#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(int T){
	ll s,tmp,tmp2;
	scanf("%lld",&s);
	if(s<=1e9){
		printf("0 0 0 1 %lld 0",s);
		return;
	}
	if(s==1000000000000000000){
		printf("0 0 1000000000 0 1 1000000000");
		return;
	}
	printf("0 0 %lld 1 %lld %lld",(s/1000000000)+1,(s/1000000000+1)*1000000000-s,1000000000);
}
signed main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
    	solve(i);
	}
}
