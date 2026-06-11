#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000000;
int eratoes[maxn+1];
long long number_of_factors(long long a){
	if(a==1) return 1;
	long long ret = 1;
	long long temp = a;
	vector<int>primes;
	while(a!=1){
		primes.push_back(eratoes[a]);
		a/=eratoes[a];
	}
	sort(primes.begin(),primes.end());
	int counter = 0;
	int curr = primes[0];
	for(int i=0; i<primes.size(); i++){
		if(primes[i]==curr) counter++;
		else{
			ret*=(counter+1);
			counter = 1;
			curr = primes[i];
		}
	}
	ret*=(counter+1);
	return ret; 
}
int main(){

	for(long long i=2; i<=maxn; i++) eratoes[i] = i;
	for(long long i=2; i*i<=maxn; i++){
		if(eratoes[i]==i){
			for(long long j=i*i; j<=maxn; j+=i) eratoes[j] = i;
		}
	}
	int n;
	cin>>n;
	long long ret = 0;
	for(long long i=1; i<=n; i++){
		ret+=i*number_of_factors(i);
	}
	cout<<ret;
}