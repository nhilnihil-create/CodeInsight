#include<bits/stdc++.h>
#define int long long
using namespace std ;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int n , m , k ; 
	cin >> n >> m >> k  ;
	vector<int> a(n+1) , b(m +1) ; 
	for(int i = 1; i <= n ; ++i)
		cin >> a[i] ; 
	for(int i = 1 ; i <= m ; ++i)
		cin >> b[i] ; 

	for(int i = 0 ; i < n   ; ++i)
	{
		a[i+1] += a[i] ; 
	}
	for(int i = 0 ; i < m ; ++i)
	{
		b[i +1] += b[i] ; 
	}
	int ans = 0 ; 
	for(int i = 0 ; i <= n ; ++i)
	{
		if(a[i] > k )
			break ;
		int rem = k- a[i] ; 
		auto it = lower_bound(b.begin() , b.end() , rem +1 ) ; 
		int idx = 0 ;
		if(it != b.begin()) 
		{
			--it ; 
			idx = it - b.begin() ; 
		}
		ans = max( ans ,idx + i  ); 

	}
	cout << ans ;

}    
















