#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;



const int m = 1e9+7;



ll  mod(ll  n){
	return (n%m + m)%m;
}



ll mul(ll i,ll n){
	return mod(mod(i)*mod(n));
}

ll add(ll i,ll n){
	return mod(mod(i)+mod(n));
}

 


ll min(ll i,ll n){
	return mod(mod(i)-mod(n));
}

ll pow(ll a,ll b,ll m){
	ll res = 1;
	while(b>0){
		if(b&1){
			res = (res*a)%m;
		}
		a = (a*a)%m;
		b = b>>1;
	}
	
	return res;

}


int main(){

ll n;
cin >> n;
if(n == 1){
	cout << 0;
}
else if(n == 2){
	cout << 2;
		
}else{
ll  ans = min(add(pow(10ll,n,m), pow(8ll,n,m)),mul(2ll,pow(9ll,n,m)) );

cout << ans << endl;

}


return 0;

}