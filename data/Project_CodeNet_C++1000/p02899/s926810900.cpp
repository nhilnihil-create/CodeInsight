#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
	
	int n ;
	cin>>n ;

	int arr[n] ;
	unordered_map<int,int> mp ;

	for(int i=0;i<n;i++){
		cin>>arr[i] ;
		mp[arr[i]]=i+1 ;
	}

	for(int i=0;i<n;i++){
		cout<<mp[i+1]<<" " ;
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