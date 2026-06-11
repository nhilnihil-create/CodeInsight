#include<bits/stdc++.h>
using namespace std;
long long LCD(long long a,long long b){
	if(a<b) swap(a,b);
	while(b){
		long long temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}
bool is_prime(long long num){
	for(long long i = 2; i*i<=num; i++){
		if(num%i==0) return false;
	}
	return true;
}
int main(){
	long long a,b;
	cin>>a>>b;
	vector<long long> divisors;
	a = LCD(a,b);
	for(long long i=1; i*i<=a; i++){
		if(a%i==0){
			divisors.push_back(i);
			if(a/i!=i) divisors.push_back(a/i);
		}
	}
	sort(divisors.begin(),divisors.end());
	int ret = 0;
	for(int i=0; i<divisors.size(); i++){
		if(is_prime(divisors[i])) ret++;
	}
	cout<<ret;
}
