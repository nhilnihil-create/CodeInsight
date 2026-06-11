#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){	
	
	int n ;
	cin>>n ;

	vector<ll> v(n) ; 
	rep(i,n){
		cin>>v[i] ;
	}	
	
	rep(i,n){
		if(v[i]==0){
			cout<<0 ;
			return ;
		}
	}

	ll prod=1 ;

	rep(i,n){
		if(v[i]<=1000000000000000000/prod){
			prod*=v[i] ;
		}
		else{
			cout<<-1 ;
			return ;
		}
	}

	cout<<prod ;
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