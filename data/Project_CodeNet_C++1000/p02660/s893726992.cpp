#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> primes;
vector<int> factor;
map<int,int> ma;
int z[1010101];
int main(){
	ll n;
	cin >> n;

	for(int i = 2; i <= 1010101; i++){
		if(z[i]) continue;
		z[i] = i;
		primes.push_back(i);
		for(int u = i; u <= 1010101; u += i){
			z[u] = i;
		}
	}
	while(n){
		bool bo = false;
		for(auto u : primes){
			if(u > sqrt(n)) break;
			if(n % u == 0){
				bo = true;
				ma[u]++;
				n /= u;
			}
		}
		if(!bo){ma[n]++;break;}
	}
	ll su = 0;
	ma[1] = 0;
	for(auto u : ma){
		ll s = 0;
		for(int i = 1; i <= 100; i++){
			s += i;
			if(s > u.second) break;
			su++;
		}
	}
	cout << su << "\n";
}
