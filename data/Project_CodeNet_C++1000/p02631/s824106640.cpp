/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with(false); cin.tie(0);cout.tie(0);
#define PI = acos(-1)
using namespace std ;
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
int main(){
	 ll n ; cin >> n ;
	 vector<ll> v(n);
	 ll x = 0 ;
	 for(int i = 0 ; i < n ; i++){
	 	    cin >> v[i];
	 	    x ^= v[i];
	 }
	 for(int i = 0 ; i < n ; i++){
	 	  cout << (x^v[i]) << " " ;
	 }
	 cout << endl;
}
