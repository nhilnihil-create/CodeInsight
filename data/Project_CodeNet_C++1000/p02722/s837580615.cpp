#include <stdio.h>
typedef long long ll;
int main(){
	ll N;
	ll cnt = 2;
	scanf("%lld",&N);
	if(N==2){
		printf("1");
		return 0;
	}
	for(ll i = 2;i*i<=N;i++){
		if(N%i==0){
			ll M = N;
			ll K = i;
			while(M%K==0) M/=K;
			cnt += M%K==1;
			if(i*i==N) continue;
			
			M = N;
			K = N/i;
			while(M%K==0) M/=K;
			cnt += M%K==1;
		}
	}
	ll M = N-1;
	for(ll i=2;i*i<=M;i++){
		cnt +=(M%i==0)*2;
		if(i*i==M) cnt--;
	}
	printf("%lld\n",cnt);
	return 0;
	ll ccnt=0;
	for(ll i=2;i<=N;i++){
		ll t = N;
		while(t%i==0) t/=i;
		ccnt += t%i==1;
	}
	printf("%lld",ccnt);
}