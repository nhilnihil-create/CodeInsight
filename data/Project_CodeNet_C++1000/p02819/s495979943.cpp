#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX_N = 1e6;
long long prime[MAX_N];
bool is_prime[MAX_N+1];

ll sieve(ll n){
	ll p = 0;
	for(ll i = 0; i <= n; i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for(ll i = 2; i <= n; i++){
		if(is_prime[i]){
			prime[p++] = i;
			for(ll j = 2*i; j <= n; j+= i)
				is_prime[j] = false;
		}
	}
	return p;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	sieve(1000000);
	int x;
	cin >> x;
	for(int i = x; i <= 1000000; ++i){
		if(is_prime[i]){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
