#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e9 + 7;

ll pot(ll a, ll b){
	ll r=1;
	while(b>0){
		if(b%2==1){
			r=(r*a)%N;
		}
		a=(a*a)%N;
		b>>=1;
	}
	return r;
	
}
int main() {
	ll x;
	cin>>x;
	ll d=pot(10,x);
	ll m=pot(8,x);
	ll p=(2*pot(9,x))%N;
	ll s=(m+d)%N;
	cout<<(s-p+N)%N;
	return 0;
}