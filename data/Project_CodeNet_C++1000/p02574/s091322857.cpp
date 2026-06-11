#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll P = 1e9+7;
const ll N = 1e6+7;


//A sieve to effectivelly factorise numbers in a range(= size)
// A number is a prime if sieve[i] == i;

vector<	ll> sieve(N);
void factor_sieve()
{
	iota(sieve.begin(),sieve.end(),0);
 
	for(ll i=2;i*i<=N;++i)
	{
		if(sieve.at(i) == i)
		{
			for(ll j = i*i;j<N;j+=i)
				if(sieve.at(j) == j)sieve.at(j) = i;
		}
	}
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t=1;
	// cin>>t;

	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n);
		for(ll i=0;i<n;++i) cin>>v[i];

		factor_sieve();
		bool ok = true;
		vector<ll> hash(N);
		for(auto x : v){

			while(x != 1){
				ll f = sieve[x];
				if(hash[f]) {ok = false; break;}
				else hash[f]++;
				while(x%f == 0) x /= f;
			}
		}

		if(!ok){
			ll gg = 0;
			for(auto &x : v) gg = __gcd(gg,x);
			if(gg == 1) cout<<"setwise coprime\n";
			else cout<<"not coprime\n";
		}
		else cout<<"pairwise coprime\n";



	}	

	return 0;
}	
