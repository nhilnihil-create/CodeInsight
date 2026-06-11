#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int arr[MAX] ;
int n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	int neg = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>arr[i] ;
		if(arr[i] < 0)
			neg++ ;
	}
	for(int i = 0 ; i < n ; ++i)
	{
		if(neg == n)
			arr[i] *= -1 ;
	}
	sort(arr , arr + n) ;
	vector< pair<int , int> >ans ;
	if(neg > 0 && neg < n)
	{
		int cnt = 0 ;
		for(int i = 1 ; i < n ; ++i)
		{
			if(arr[i] >= 0)
				arr[i-cnt] = arr[i] ;
			else
			{
				cnt++ ;
				ans.emplace_back(arr[n-1] , arr[i]) ;
				arr[n-1] -= arr[i] ;
			}
		}
		n -= cnt ;
	}
	int cur = arr[0] ;
	for(int i = 1 ; i < n-1 ; ++i)
	{
		ans.emplace_back(cur , arr[i]) ;
		cur -= arr[i] ;
	}
	if(arr[n-1] >= 0)
		ans.emplace_back(arr[n-1] , cur) ;
	else
		ans.emplace_back(cur , arr[n-1]) ;
	cout<<ans.back().first - ans.back().second<<"\n" ;
	for(int i = 0 ; i < ans.size() ; ++i)
	{
		if(neg == n)
		{
			ans[i].first *= -1 , ans[i].second *= -1 ;
			if(i == ans.size() - 1)
				swap(ans[i].first , ans[i].second) ;
		}
		cout<<ans[i].first<<" "<<ans[i].second<<"\n" ;
	}
	return 0 ;
}		