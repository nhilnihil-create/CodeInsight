#include <iostream>

using namespace std;

#define PRIMENUM 300000

int isPrime[PRIMENUM];

void makePrimeNumber(){

	isPrime[2]=1;
	isPrime[3]=1;

	for(int i=4;i<PRIMENUM;i++){
		int flag=0;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			isPrime[i]=1;
			//cout<<i<<endl;
		}	
	}

}

int main(){

	makePrimeNumber();

	int ans=0;
	int n;

	while(cin>>n){
		ans=0;
		if(n==0)break;

		for(int i=n+1;i<=2*n;i++){
			if(isPrime[i]==1)ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}