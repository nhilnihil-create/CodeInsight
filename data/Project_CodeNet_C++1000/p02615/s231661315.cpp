#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
	
	int n ;
	cin>>n ;

	vector<int> v(n) ;

	for(int i=0;i<n;i++){
		cin>>v[i] ;
	}

	sort(v.begin(),v.end()) ;

	reverse(v.begin(),v.end()) ;

	vector<ll> b; 

	for(int i=0;i<n;i++){
		b.push_back(v[i]) ;
		if(i!=0)
			b.push_back(v[i]) ;
	}

	ll ans=0 ;

	for(int i=0;i<n-1;i++){
		ans+=b[i] ;
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