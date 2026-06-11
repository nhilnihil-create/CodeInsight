#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define u(x, a, b) for(ll x = a; x < b; x++)
#define d(x, a, b) for(ll x = a; x > b; x--)

typedef long long ll;
typedef long double ld;

#define MAXI 100010
#define MOD 1000000007

vector<ll> primes;

int main(){
	ll a, b;
	cin >> a >> b;
	
	primes.push_back(2);
	u(one, 3, 1000020){
		bool div = false;
		u(two, 0, primes.size()){
			if(primes[two]*primes[two] > one){two = primes.size();}
			else if(one%primes[two]==0){div = true; two = primes.size();}
		}
		
		if(!div){primes.push_back(one);}
	}
	
	if(a<b){swap(a,b);}
	while(b>0){
		ll c = b;
		b = a%b;
		a = c;
	}
	
	ll ans = 1;
	
	u(one, 0, primes.size()){
		if(a%primes[one]==0){ans++;}
		while(a%primes[one]==0){a/=primes[one];}
	}
	
	if(a!=1){ans++;}
	
	cout << ans;
	
}
