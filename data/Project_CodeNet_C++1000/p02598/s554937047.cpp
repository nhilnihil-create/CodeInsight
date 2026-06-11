#include<bits/stdc++.h>
#define int long long
using namespace std ;


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int n , k ; 
	cin >> n >> k  ;
	vector<int> a(n) ; 
	for(int i = 0; i < n ;++i)
		cin >> a[i]; 
	int lo = 1, hi = 1e10 ;
	while(lo < hi)
	{
	 	int mid = (lo +hi)/2 , r = 0 ; 
	 	for(int i = 0 ; i < n ; ++i)
	 	{
	 		r +=ceil((double)a[i]/mid) ; 
	 		
	 	}
	 	if(r <= n + k )
	 	{
	 		hi = mid ;	
	 	}
	 	else 
	 		lo = mid +1 ; 
	}
	cout << hi ; 
}
