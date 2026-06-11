#include<bits/stdc++.h>
using namespace std; 
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
 
typedef long long int ll; 
typedef long double ld; 

ll mod = 1e9+7;

ll add(ll a, ll b){
	a = a%mod;
	b = b%mod;
	return (mod+(a+b)%mod)%mod;
}

ll mul(ll a, ll b){
	a = a%mod;
	b = b%mod;
	return (mod+(a*b)%mod)%mod;
}

vector<ll> prime(1000001, -1);

void sieve(ll ma){
	
	for(ll i=2;i<=ma;++i){
		if(prime[i]==-1){
			for(ll j=2*i;j<=ma;j+=i){
				if(prime[j]==-1){
					prime[j] = i;
				}
			}
		}
	}
}

int main(){
	
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	sieve(1000001);
	
	ll n;
	cin>>n;
	
	ll arr[n];
	unordered_map<ll,ll> mp;
	ll flg = 0;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		ll x = arr[i];
		while(x>1){
			ll val;
			if(prime[x]==-1){
				val = x;
			}
			else{
				val = prime[x];
			}
			mp[val]++;
			if(mp[val]>1){
				flg = 1;
			}
			while(x%val==0){
				x = x/val;
			}
		}
	}
	
	if(flg==0){
		cout<<"pairwise coprime"<<endl;
	}
	else{
		ll x = arr[0];
		for(ll i=1;i<n;i++){
			x = __gcd(arr[i], x);
		}
		if(x==1){
			cout<<"setwise coprime"<<endl;
		}	
		else{
			cout<<"not coprime"<<endl;
		}
	}
	
}
