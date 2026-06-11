#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007;

void solve(){

	string ans="" ;

	ll n ;
	cin>>n ;

	while(n>0){
		n-- ;
		ans+='a'+n%26 ;
		n/=26 ;
	}

	reverse(ans.begin(),ans.end()) ;
	
	cout<<ans ;


}


int main(){

		ll y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}