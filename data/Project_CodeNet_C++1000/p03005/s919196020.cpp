#include<bits/stdc++.h>

#define I inline void 

using namespace std ; 

using ll = long long ; 
using ld = long double ; 

const int N = 2e6 + 7 ; 

// How interesting!

int n; 


int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ; 
	//freopen("in.in", "r" , stdin) ;
	int k ; 
	cin >> n >>  k ; 
	if(k == 1) cout<< 0 ; 
	else cout<< n - k ; 

	return 0 ; 
}