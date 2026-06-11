#include "bits/stdc++.h"

using namespace std;

long long int N,M,K,L,R,H,W;

const long long int MOD=1000000007;

int main(){
	while(cin>>N,N){
		M=0;
		for(int i=2;i<=N;i++){
			if((N*2)%i)continue;
			K=N*2/i;
			R=K+i-1;
			if(R&1)continue;
			R/=2;
			L=R-i+1;
			if(R+L==K&&L>=1)M++;
		}
		cout<<M<<endl;
	}
	
	return 0;
}
