#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	map<string,int> mp ;

	for(int i=0;i<n;i++){
		string s ;
		cin>>s ;
		mp[s]++ ;
	}	

	int mx=0 ;

	for(auto x:mp){
		mx=max(mx,x.second) ;
	}

	for(auto x:mp){
		if(x.second==mx){
			cout<<x.first<<"\n" ;
		}
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