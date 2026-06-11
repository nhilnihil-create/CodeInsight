#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int n ;
	cin>>n ;

	vector<int> v(n) ;

	for(int i=0;i<n;i++){
		cin>>v[i] ;
	}

	vector<int> temp=v ;

	sort(v.begin(),v.end()) ;
	
	for(int i=0;i<n;i++){

		if(temp[i]==v[n-1]){
			cout<<v[n-2]<<"\n" ;
		}
		else{
			cout<<v[n-1]<<"\n" ;
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