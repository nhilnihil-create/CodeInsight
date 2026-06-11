#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pii;

int32_t main()
{
	int x , n ;
	cin >> x >> n ;

	int a[500] ;
	memset(a , 0 , sizeof(a)) ;

	if(n == 0)
		return cout << x , 0 ;

	for(int i = 0 ; i < n ; i++){
		int y ;
		cin >> y ;
		a[y]++ ;
	}

	int diff = INT_MAX , ans ; 

	for(int val = 0 ; val < 200 ; val++){
		if(!a[val] && abs(val - x) < diff){
			diff = abs(val - x) ;
			ans = val ;
		}
		else if(!a[val] && abs(val - x) == diff && ans > val)
			ans = val ;
	} 

	cout << ans ;
	return 0;
}        