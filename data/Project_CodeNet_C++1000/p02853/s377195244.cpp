#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int arr[MAX] ;
int x , y ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>x>>y ;
	int ans = 100000 * max(0 , 4 - x) ;
	ans += 100000 * max(0 , 4 - y) ;
	if(x == 1 && y == 1)
		ans += 4 * 100000 ;
	return cout<<ans<<"\n" , 0 ;
}		