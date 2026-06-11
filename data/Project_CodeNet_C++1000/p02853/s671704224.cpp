#include<bits/stdc++.h>
//#pragma GCC optimize("trapv")
#define I inline void 

using namespace std ; 
using ll = long long ; 
using ld = long double ; 
	
const int N = 1e5 + 7 , mod = 1e9 + 7 ; 

// How interesting!
	
int n , m; 
	
int main(){	
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ; 
	//freopen("in.in" , "r" ,stdin) ; 
	ll x , y ; 
	cin >> x >> y ;
	cout<< max(0ll  , ( 4 - x ) * 100000) + max(0ll , (4 - y) ) * 100000  + (x + y == 2 ? 400000 : 0) ;  
	return 0 ; 
	
}