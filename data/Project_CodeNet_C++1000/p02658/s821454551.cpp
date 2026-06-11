#include<stdio.h>
#define ll long long int
int main(){
	ll n;
	scanf ("%lld",&n);
	ll num[n]={};
	ll res=1;
    for (ll i=0;i<n;i++){
    	scanf("%lld",&num[i]);
	}
	for (ll i=0;i<n;i++){
		if (num[i]==0){
			printf("0\n");
			return 0;
		}
	}
	
	for (int i=0;i<n;i++){
		if (num[i]<=1000000000000000000/res){
			res*=num[i];
		}else{
			printf ("-1\n");
			return 0;
		}
	}
	printf ("%lld",res);
	return 0;
}
