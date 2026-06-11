#include<bits/stdc++.h>
using namespace std;
int main(){
	long long N;
	scanf("%lld",&N);

	long long ans=0;
	for(long long L=1;L<=N;L++){
		ans+= ((N-L+2)*(N-L+1))/2;
	}

	for(int i=0;i<N-1;i++){
		long long u,v;
		scanf("%lld%lld",&u,&v);

		if(u>v)swap(u,v);
		
		ans-=u*(N-v+1);
	}

	printf("%lld",ans);

	return 0;
}