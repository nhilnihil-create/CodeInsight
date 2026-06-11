#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int h,a ;
	cin>>h>>a ;

	int count=0 ;

	while(h>a*count){
		count++ ;
	}

	cout<<count ;

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