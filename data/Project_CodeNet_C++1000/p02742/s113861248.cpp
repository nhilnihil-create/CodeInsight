#include"bits/stdc++.h"
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define bug( x ) cerr << #x << '=' << x << '\n' ;


long long H,W;





int main(){

	IOS

	cin >> H >> W ;

	
	if(H == 1 || W == 1 )cout<<"1\n";

	else cout << (H*W+1)/2 << '\n' ;

}