/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define PI = acos(-1)
using namespace std ;
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
int main(){
	 fastio ; 
	 ll m = 1000000007;
     ll n ; cin >> n ;
     vector<ll> v(n);
     for(ll i = 0 ; i < n ; i++){
     	cin >> v[i];
	 }
	 ll f[68] = {0};
//	 for(auto x:f) cout << x << " ";
//	 cout << endl;
	 for(ll i = 0 ; i < n ; i++){
	 	  for(ll j = 0 ; j < 61  ; j++){
	 	  	    if((v[i] & (1LL << j)))
	 	  	       f[j]++;
		   }
	 }
	// for(auto x :f) cout << x << " ";
	// cout << endl;
	 ll res = 0 ;
	 for(ll i = 0 ; i < 61 ; i++){
	 	  ll x = f[i];
	 	  ll z = (n-x);
	 	  ll ans = power(2 , i , m);
	 	  //cout << x << " " << z << " " << ans << endl;
	 	  ll ans2 = ( x % m * z % m) % m ;
	 	  ans2 = ( ans2 % m * ans%m) % m ;
	 	  res = ( res % m + ans2%m) %m ;
	 }
	 cout << (res)%m << endl;
}
