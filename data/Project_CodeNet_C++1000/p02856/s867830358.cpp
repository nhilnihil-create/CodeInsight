#include<bits/stdc++.h>
//#pragma GCC optimize("trapv")
#define I inline void 

using namespace std ; 
using ll = long long ; 
using ld = long double ; 
	
const int N = 2e5 + 7 , mod = 1e9 + 7 ; 

// How interesting!
	
int n , m; 

ll a[N] ; 
	
int main(){	
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ; 

	int n ; 
	cin >> n ; 
	ll ans = 0 ; 

	for(int i = 0 ;i < n;i++){
		ll x , y; 
		cin >> x >> y ;
	      ans+= 9 * y + x * y ;
	}
	cout<< (ans - 10) / 9 ; 
	return 0 ; 
	
}