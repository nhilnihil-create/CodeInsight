#include <iostream>
using namespace std;
int prime[250000];
int n,cnt;



int main(){
	prime[1]=0;
	for(int i=2;i<250000;i++){
		prime[i]=1;
	}
	for(int i=2;i<=500;i++){
		if(prime[i]==0)continue;
		int k=i*i;
		while(k<250000){
			prime[k]=0;
			k+=i;
		}
	}

	while(1){
		cin >>n;
		if(n==0)break;
		cnt=0;
		for(int i=n+1;i<=2*n;i++){
			cnt+=prime[i];
		}
		cout <<cnt<<endl;
	}
}