#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	int prime[250000] = {0};

	for(int i=2;i<250000;i++){
		prime[i] = isPrime(i);
	}
	for(int i=1;i<250000;i++){
		prime[i] += prime[i-1];
	}

	int n;
	while(cin >> n,n){
		cout << prime[2*n] - prime[n] << endl;
	}
	return 0;
}