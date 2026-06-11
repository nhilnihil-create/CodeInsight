#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n,m;
	cin >> n >> m;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin >> a[i];
		a[i]/=2;
	}
	bool same=true;
	while(a[0]%2==0){
		for(int i=0;i<n;i++){
			if(a[i]%2!=0){
				cout << 0 << endl;
				return 0;
			}
			a[i]/=2;
		}
		m/=2;
	}
	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			cout << 0 << endl;
			return 0;
		}
	}
	ll com;
	if(n==1) com=a[0];
	else{
		com=a[1]/__gcd(a[1],a[0])*a[0];
		for(ll i=2;i<n;i++){
			com=a[i]/__gcd(a[i],com)*com;
			if(com>2*m){
				cout << 0 << endl;
				return 0;
			}
		}
	}
	ll res=0;
	ll count=com;
	while(count<=m){
		res++;
		count+=com*2;
	}
	cout << res << endl;
}
