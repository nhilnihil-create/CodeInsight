#include<cstdio>

int n;
int prime[1000000];
int cnt[1000000];
int main(void){
	for(int i=2;i<=500000;i++){
		if(prime[i]==0){
			for(int j=i*2;j<=500000;j+=i)prime[j]=1;
		}
	}
	for(int i=2;i<=500000;i++)cnt[i]=cnt[i-1]+(1-prime[i]);
	prime[1]=1;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",cnt[n*2]-cnt[n]);
	}
	return 0;
}