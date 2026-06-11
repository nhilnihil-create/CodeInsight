#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int n ;
	cin>>n ;

	vector<int> a(n) ;


	rep(i,n){
		cin>>a[i] ;
	}	

	if(n==1){
		cout<<"Yes" ;
		return ;
	}

	for(int i=n-2;i>=0;i--){
		if(a[i]>a[i+1]){
			a[i]-- ;
		}

	}

	for(int i=n-2;i>=0;i--){
		if(a[i]>a[i+1]){
			cout<<"No" ;
			//cout<<a[i]<<" " <<a[i+1] ;
			return ;
		}
	}

	cout<<"Yes" ;

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