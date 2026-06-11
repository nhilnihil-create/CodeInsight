#include<bits/stdc++.h>
using namespace std;
int solve(int a){
	int curr = 0;
	int counter = 1;
	while(curr<=a) curr+=counter++;
	return counter-2;
}
int main(){
	long long n;
	cin>>n;
	vector<int>primes;
	for(long long i=2; i*i<=n; i++){
		if(n%i==0){
			int counter = 0;
			while(n%i==0){
				counter++;
				n/=i;
			}
			primes.push_back(counter);
		}
	} 
	if(n!=1) primes.push_back(1);
	int ret = 0;
	for(int i=0; i<primes.size(); i++){
		ret+=solve(primes[i]);
	}
	cout<<ret;
}