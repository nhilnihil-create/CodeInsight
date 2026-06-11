#include <bits/stdc++.h>

using namespace std ;

const int MAX = 3e5 + 10 ;

int arr[MAX] , freq[MAX] , suff[MAX] , mark[MAX] ;
vector<int>er[MAX] ;
int n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	vector<int>v ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>arr[i] ;
		freq[arr[i]]++ ;
	}
	for(int i = 0 ; i < n ; ++i)
	{
		if(freq[arr[i]])
			v.push_back(freq[arr[i]]) ;
		freq[arr[i]] = 0 ;
	}
	sort(v.rbegin() , v.rend()) ;
	int sz = v.size() ;
	for(int i = sz-1 ; i >= 0 ; --i)
		suff[i] = suff[i+1] + v[i] ;
	int idx = sz-1 ;
	for(int i = 1 ; i <= n ; ++i)
	{
		while(idx >= 0 && v[idx] < i)
			idx-- ;
		int k = idx+1 + suff[idx+1] / i ;
		er[k].push_back(i) ;
	}
	int k = n ;
	for(int i = 1 ; i <= n ; ++i)
	{
		while(mark[k])
			k-- ;
		cout<<k<<"\n" ;
		for(auto &j : er[i])
			mark[j] = 1 ;
	}
	return 0 ;
}		