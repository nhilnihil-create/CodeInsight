#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
	
	ll h,w ; 
	cin>>h>>w ;

	ll ans=h*w ;

	if(h==1||w==1){
		cout<<1 ;
		return ;
	}


	if(ans%2==0)
		cout<<ans/2 ;
	else
		cout<<(ans+1)/2 ;
	

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