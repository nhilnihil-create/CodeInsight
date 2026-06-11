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
	//freopen("in.in" , "r" ,stdin) ; 
	cin >> n ; 
	ll sum = 0 ; 
	for(int i =0 ;i < n;i++){
		cin >>a[i] ; 
		sum+=a[i] ;
	}
	ll suml = 0 ; 
	ll ans = 1e18 ; 
	for(int i = 0 ;i < n;i++){
		suml+=a[i] ; 
		sum-=a[i] ; 
		ans = min(ans , abs(suml - sum) ) ; 
	}
	cout<< ans ; 
	return 0 ; 
	
}