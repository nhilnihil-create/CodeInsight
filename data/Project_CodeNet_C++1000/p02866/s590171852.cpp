#pragma GCC optimize(2) 
#include<iostream>
 
using namespace std;
const int mod=998244353;
long long a[100010];
long long n,x;
long long ksm(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1){
			res=(res*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
 
int main(){
	scanf("%lld",&n);
	int flag=0;
	scanf("%lld",&x);
	int ans=x;
	if(x!=0) flag=1;
	for(int i=1;i<n;i++){
		scanf("%lld",&x);
		a[x]++;
		if(x==0) flag=1;
		if(x>ans){
			ans=x;
		}
	}
	
	if(flag){
		printf("0\n");
	}
	else{
	long long sum=1;
		for(int i=1;i<ans;i++){
			if(a[i]==0){
				flag=1;
				break;
			}
			sum*=ksm(a[i],a[i+1]);
			sum%=mod;
		}
		if(flag) printf("0\n");
		else printf("%lld\n",sum);
	}
	return 0;
} 