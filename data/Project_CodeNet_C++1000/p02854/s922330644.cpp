#include <bits/stdc++.h>

using namespace std ;

const int MAX = 2e5 + 10 ;

int arr[MAX] ;
int n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	long long sum = 0 , cur = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>arr[i] ;
		sum += arr[i] ;
	}
	long long ans = 4e18 ;
	for(int i = 0 ; i < n-1 ; ++i)
	{
		cur += arr[i] ;
		sum -= arr[i] ;
		ans = min(ans , abs(sum - cur)) ;
	}
	return cout<<ans<<"\n" , 0 ;
}		