#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int arr[MAX] ;
int n , k ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>k ;
	int ans = n-k ;
	if(k == 1)
		ans = 0 ;
	return cout<<ans<<"\n" , 0 ;
}		