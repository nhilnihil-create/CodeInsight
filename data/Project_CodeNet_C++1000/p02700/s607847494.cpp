#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){	
	
	int a,b,c,d ;
	cin>>a>>b>>c>>d ;

	while(true){
		c=c-b ;
		if(c<=0){
			cout<<"Yes" ;
			return  ;
		}

		a=a-d ;
		if(a<=0){
			cout<<"No" ;
			return  ;
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