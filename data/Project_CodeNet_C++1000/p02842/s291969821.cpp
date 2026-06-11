#include"bits/stdc++.h"
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define bug( x ) cerr << #x << '=' << x << '\n' ;


int n ,i;



int main(){

	//IOS

	cin >> n ;

	for ( i = 1; i <=50000; ++i)
	{
		if( (int)(i*1.08) ==n){
			cout<<i;
			break;
		}
		//bug(i*1.08)
	}

	if(i==50001)cout<<":(";

	
 
}