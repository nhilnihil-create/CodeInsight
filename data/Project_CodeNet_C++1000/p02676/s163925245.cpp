#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;
	string s;
	cin>>s ;

	if(s.length()>n){
		string t=s.substr(0,n) ;
		t=t+"..." ;
		cout<<t ;
	}
	else
	{
		cout<<s ;
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