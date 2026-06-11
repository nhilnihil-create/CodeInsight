#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
//ll mod = 1000000007;
#define mod 1000000007

ll pow(ll m, ll n){
	  if(n==0) return 1;
	  if(n%2==1)
			return ((pow(m,(n-1)/2) % mod) * (pow(m,(n-1)/2) % mod) * (m % mod)) % mod;
	  else
			return ((pow(m,n/2) % mod) * (pow(m,n/2) % mod)) % mod;
}


ll mypow(ll m, ll n){
	  if(n==0) return 1;
	  if(n%2==1)	return mypow(m*m%mod,n/2) % mod * m % mod;
	  return mypow(m*m%mod,n/2) % mod;
}


int main(){

	  ll m,n; cin >> m >> n;
	  cout << mypow(m,n)%mod << endl;
}