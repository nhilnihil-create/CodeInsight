#include <bits/stdc++.h>

using namespace std; 
typedef long long ll;
bitset<10000010> primes;
ll ub;
vector<ll> lprimes;
void crivo(int a){
	primes.set();
	primes[0] = primes[1] = 0;
	for(int i = 4;i <= a; i += 2){
		primes[i] = 0;
	}
	for(int i = 3; i * i <= a; i += 2){
		if(primes[i]){
			for(int j = i * i; j <= a; j += i){
				primes[j] = 0;
			}
		}
	}
}

int main(){
	ub = 10000010;
	crivo(ub);
	int a;
	cin>>a;
	int cont = 0;
	while(!primes[a + cont]){
		cont++;
	}
	cout<<a + cont<<endl;
	return 0;
}