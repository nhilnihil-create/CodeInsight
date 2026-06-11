#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	string s ;
	cin>>s ;

	ll sum=0 ;
	for(int i=0;i<s.length();i++){
		sum+=s[i]-'0' ;
	}

	if(sum%9==0)
		cout<<"Yes" ;
	else
		cout<<"No" ;

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