#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<S<<endl
using namespace std;


bool prime[300001]={false};
void isPrime(){
	prime[1]=true;
	for(int i=2;i*i<300000;i++){
		if(!prime[i]){
			for(int j=2*i;j<300000;j+=i){
				prime[j]=true;
			}
		}
	}

	return;
}

int main(){
	isPrime();
	int N;
	while(cin>>N,N){
		int count=0;
		REP(i,N+1,2*N+1){
			if(!prime[i]) count++;
		}
		p(count);
	}
	return 0;
}