#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	n=n%10 ;

	if(n==2||n==4||n==5||n==7||n==9){
		cout<<"hon" ;
	}
	else if(n==0||n==1||n==6||n==8){
		cout<<"pon" ;
	}
	else
		cout<<"bon" ;

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