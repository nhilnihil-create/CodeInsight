#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
	
	int n ;
	cin>>n ;

	int amount=1000 ;
	
	while(amount<n){
		amount+=1000 ;
	}	
	
	cout<<amount-n ;

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