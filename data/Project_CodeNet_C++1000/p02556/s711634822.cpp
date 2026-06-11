/*
 author : nit1n
 created : 14/09/2020 23:35:48
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int N =2e5 + 5 ;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;
                                                                                
    int n ; 
    cin >> n ;
	vector<pair<int,int>> a(n) ; 
	for(int i = 0 ; i < n ; ++i)
	{
		int u , v ; 
		cin >> u >> v ; 
		a[i] = make_pair(u,v) ; 
	}
	int ans = 0;
	sort(a.begin() , a.end()) ; 
	int mn = a[0].first + a[0].second ; 
	int mx = a[0].second - a[0].first ; 
	for(int i = 1; i < n ; ++i)
	{
		ans = max(ans ,max( a[i].first + a[i].second - mn ,	a[i].first - a[i].second + mx)) ; 
		mn= min(mn, a[i].first + a[i].second) ;
		mx= max(mx , -a[i].first + a[i].second ) ;
	}
	cout << ans ;
}

