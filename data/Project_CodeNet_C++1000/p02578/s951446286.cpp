#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	
	int n;
	cin>>n ;

	vector<int> v(n) ;

	for(int i=0;i<n;i++){
		cin>>v[i] ;
	}

	vector<int> temp(n) ;

	temp=v ;

	int mx=v[0] ;

	for(int i=1;i<n;i++){
		if(v[i]<mx){
			v[i]=mx ;
		}

		mx=max(v[i],mx) ;
	}

	ll ans=0 ;
	for(int i=0;i<n;i++){
		ans+=v[i]-temp[i] ;
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