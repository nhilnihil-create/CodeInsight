#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pii;

int32_t main()
{
	int x , y ;
	cin >> x >> y ;

	if(y & 1)return cout <<"No" , 0 ;

	y /= 2 ;
	int a = 2 * x - y , b = y - x ;

	if(a >= 0 && b >= 0)
		cout << "Yes";
	else 
		cout <<"No" ;
	return 0;
}        