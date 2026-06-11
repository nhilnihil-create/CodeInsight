#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	string s ;
	cin>>s ;

	for(int i=0;i<(int)s.length();i++){
		if(s[i]=='?'){
			s[i]='D' ;
		}

	}	
	
	cout<<s ;

}


int main(){

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}