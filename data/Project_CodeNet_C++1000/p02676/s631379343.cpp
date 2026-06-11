/*
author : nit1n
created :  31.08.2020 15:31:30
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	int k ;
	string s ; 
	cin >> k >> s ;
	if(s.size() <=k)
		cout << s  ; 
	else
		cout << s.substr(0, k ) << "..."  ;
}
