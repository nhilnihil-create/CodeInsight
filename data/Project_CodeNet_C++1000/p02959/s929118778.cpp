#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	vector<int> a(n+1) ;
	vector<int> b(n) ;

	rep(i,n+1){
		cin>>a[i] ;
	} 

	rep(i,n){
		cin>>b[i] ;
	}

	ll ans=0 ;

	rep(i,n){

		int x=min(a[i],b[i]) ;
		ans+=x ;
		b[i]-=x ;
		x=min(a[i+1],b[i]) ;
		ans+=x ;
		a[i+1]-=x ;

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