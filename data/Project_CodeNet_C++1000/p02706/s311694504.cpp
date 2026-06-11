#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n,m ;
	cin>>n>>m ;

	ll arr[m] ;
	ll sum=0 ;

	for(int i=0;i<m;i++){
		cin>>arr[i] ;
		sum+=arr[i] ;
	}

	if(sum>n){
		cout<<-1 ;
	}
	else{
		cout<<n-sum ;
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