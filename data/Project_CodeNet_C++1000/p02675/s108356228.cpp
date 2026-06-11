/*
author : nit1n
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int n ; 
	cin >> n ; 
	int num = n %10 ; 
	if(num == 2 || num ==4 || num == 5 || num == 7 ||num == 9 )
		cout << "hon"; 
	else if(num ==0 || num ==1 || num ==6 || num ==8)
		cout << "pon" ; 
	else 
		cout <<"bon" ; 

}
