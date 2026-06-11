#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int prime[123457*2];
bool is_prime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return n!=1;
}
int main(){
	prime[1]=0;
	for(int i=2;i<=123456*2;i++){
		if(is_prime(i)){
			prime[i]=prime[i-1]+1;
		}else prime[i]=prime[i-1];
	}
	int n;
	while(cin>>n,n){
		cout<<prime[2*n]-prime[n]<<endl;
	}
}