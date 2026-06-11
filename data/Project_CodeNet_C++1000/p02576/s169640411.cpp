#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n,x,t ;
	cin>>n>>x>>t ;

	int time=0 ;
	int total=0 ;
	while(total<n){
		total+=x ;
		time+=t ;
	}	

	cout<<time ;

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