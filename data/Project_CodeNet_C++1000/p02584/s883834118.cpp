#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	ll x,k,d ;
	cin>>x>>k>>d ;

	x=abs(x) ;

	ll ans=0 ;
	if(x/d-k>0){
		ans=x-k*d ;
	}
	else{

		ll e=x/d ;
		k-=e ;
		x-=e*d ;

		if(k%2==1)
			x=abs(x-d) ;
		ans=x ;

	}
	
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