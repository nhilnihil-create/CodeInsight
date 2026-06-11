/*
author : nit1n
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
int a[3][3] ; 
bool vis[3][3] ; 
void check(int u)
{
	for(int i = 0 ;i < 3; ++i)
	{
		for(int j = 0; j < 3 ; ++j)
		{
			if(a[i][j] == u)
				vis[i][j] = true ; 
		}
	}
}
bool bingo()
{
	for(int i = 0; i < 3; ++i)
	{
		if(vis[i][0] == true && vis[i][1] == true && vis[i][2] == true )
			return true  ; 
	}
	for(int j = 0 ; j < 3 ;++j)
	{
		if(vis[0][j] == true && vis[1][j] == true && vis[2][j] == true)
			return true ;
	}
	if(vis[1][1] == true && vis[0][0] == true && vis[2][2] == true)
		return true ; 
	if(vis[2][0] == true && vis[1][1] == true && vis[2][0] == true)
		return true ; 
	return false ; 		
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	for(int i = 0 ; i < 3 ;++i)
	{
		for(int j = 0; j < 3 ; ++j)
			cin >>a[i][j] ; 
	}
	int n ;
	cin >>n  ;
	for(int i = 0 ; i  <n ; ++i)
	{
		int u ; 
		cin >> u ; 
		check(u) ; 
		
	}
	bool ans = bingo() ; 
	if(ans)
		cout << "Yes" ; 
	else 
		cout << "No" ;

}
