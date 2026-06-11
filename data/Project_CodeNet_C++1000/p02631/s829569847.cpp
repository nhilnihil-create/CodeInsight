#include<bits/stdc++.h>
#define endl "\n"
//#define int long  long 

using namespace std ; 
	 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int n ;
	cin >> n ; 
	vector<int> a(n) ; 
	for(int i = 0; i < n ; ++i)
	{
		cin >> a[i] ; 
	}
	int t = a[0] ; 
	for(int i = 1 ; i < n; ++i)
	{
		t ^= a[i] ; 
	}
	for(int i = 0;  i < n ; ++i)
		cout << (t^a[i]) << " " ;


}       



