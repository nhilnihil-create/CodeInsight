/*
author : nit1n
created : 31.08.2020 16:40:58
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;

const double pi = acos(-1) ; 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int a , b , h ,m ; 
	cin >> a >> b >> h >> m ; 
	if(h == 12) h = 0 ; 
	double l  = 0.5*(h*60 + m) ; 
	double r = 6*m ; 
	double d = abs ( l - r) ; 
	double k = min(d  , 360 - d) ; 
	double  ans = pow(a ,2) + pow(b , 2)  - 2*a*b*(cos(k*pi/180)) ;
//	cout << pow(a ,2) + pow(b , 2) << " " << cos(k); 
	cout << fixed << setprecision(18) <<sqrt( ans) ; 

}
