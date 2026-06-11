#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n,k ;
	cin>>n>>k ;

	vector<int> v(n) ;

	rep(i,n){
		cin>>v[i] ;
	}

	sort(v.rbegin(),v.rend()) ;

	if(k<n){

		ll x=0 ;
		for(int i=k;i<n;i++){
			x+=v[i] ;
		}

		cout<<x ;
	}
	else{
		cout<<0 ;
	}

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