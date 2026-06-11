#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=998244353;

void solve(){

	int n ;
	cin>>n ;

	ll ans=0 ;

	for(int a=1;a<=n;a++){
		ans+=(n-1)/a ;
	}

	cout<<ans ;

}


int main(){

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}