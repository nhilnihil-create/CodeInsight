#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	vector<int> v(n+1) ;
	unordered_map<int,int> mp ;

	for(int i=2;i<=n;i++)
	{
		cin>>v[i] ;
		mp[v[i]]++ ;
	}

	for(int i=1;i<=n;i++){
		cout<<mp[i]<<"\n" ; 
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