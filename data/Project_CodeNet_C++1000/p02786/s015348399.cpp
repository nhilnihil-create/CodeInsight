#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;


ll recur(ll n){

	if(n==1)
		return 1 ;

	ll l=recur(n/2) ;

	return 2*l+1 ; 

}

void solve(){
	
	ll n ;
	cin>>n ;

	ll ans=recur(n) ;		
	cout<<ans ;

}

int main(){
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}