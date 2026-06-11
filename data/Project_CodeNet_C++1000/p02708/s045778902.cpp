#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll moder = 1000000007;
int main(){
	ll n,k;
	cin>>n>>k;
	long long ret = 0;
	for(ll i=k; i<=n+1; i++){
		ll lower = i*(i-1)/2;
		lower%=moder;
		ll upper = n*i-i*(i-1)/2;
		ret+=upper-lower+1;
		ret%=moder;
	}
	cout<<ret;
}