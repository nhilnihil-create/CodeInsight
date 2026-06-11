#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	ll t ;
	int n ;
	cin>>t>>n ;

	vector<int> v(n) ;

	ll sum=0 ;
	rep(i,n){
		cin>>v[i] ;
		sum+=v[i] ;
	}
	
	if(sum>=t)	
	{
		cout<<"Yes" ;
	}
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