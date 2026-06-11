#include<bits/stdc++.h>
#define int long  long 
#define ar array

using namespace std ;
                                                                                              
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int n  ;
	cin >> n ; 
	int ans = 0 ; 
	for(int i =1 ; i <= n ; ++i)
	{
		for(int j =1 ; j <= n ; ++j)
		{
			for(int k =1 ; k <= n ; ++k)
			{
				int g = __gcd(__gcd(i,j) , k) ; 
				ans += g ; 
			}
		}

	}
	cout << ans ;
}






