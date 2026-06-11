#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007;

void solve(){

	int n ;
	cin>>n ;

	string s ;
	cin>>s ; 

	if(n%2!=0)
	{
		cout<<"No" ;
		return ;
	}

	string t=s.substr(n/2) ;
	t=t+t ;

	if(s==t){
		cout<<"Yes" ;

	}
	else{
		cout<<"No" ;
	}

}


int main(){

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}