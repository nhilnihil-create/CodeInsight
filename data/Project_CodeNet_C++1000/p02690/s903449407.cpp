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
ll power1( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power1(b*b,e/2);
    return power1(b*b,e/2);
}
ll f(ll x){
	if(x%4 == 0){
		return x ;
	}
	else if(x%4 == 1){
		return 1 ;
	}
	else if(x%4 == 2){
		return (x+1) ;
	}
	else return 0 ;
}
int main(){
	 ll X ; cin >> X ;
	 //cout << power(2,5);
	 bool flag = 0 ;
	 for(ll i = -3000 ; i <= 3000 ; i++){
	 	   for(ll j = -3000 ; j <= 3000 ; j++){
	 	   	      ll x = power1(i,5);
	 	   	      ll y = power1(j,5);
	 	   	      if((x-y)==X){
	 	   	      	    cout << i << " " << j << endl;
	 	   	      	    flag = 1 ;
	 	   	      	     break;
				}
			}
		  if(flag) break ;
	 }
}
