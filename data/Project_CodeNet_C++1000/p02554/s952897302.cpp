#include<bits/stdc++.h>
#include<vector>
#include<set>
#define ll long long int

using namespace std;
#define mod 1000000007





ll power(ll x, ll n){
	ll res = 1;
	while(n){
		if(n%2) res = ((res%mod)*(x%mod))%mod;
		x = ((x%mod)*(x%mod))%mod;
		n /= 2;
	}
	return res;
}

int main(){
	ll n;
	cin >> n;
	ll res = (power(10, n)-2*power(9, n)+power(8,n)+2*mod)%mod;
	printf("%lld\n", res);
}