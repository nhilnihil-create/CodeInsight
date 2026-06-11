#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define N 0
#define INF 0x3f3f3f3f
#define LL long long
#define mz(x) ms(x,0)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcopy(x,y,sizeof(y))
#define MOD 1000000007

using namespace std ;

int a[5][5] ;
bool mark[5][5] ;
map<int, pair<int, int> > mp ;

int main()
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
		{
			scanf("%d", &a[i][j]) ;
			mp[a[i][j]] = make_pair(i, j) ;
		}
			
	int n ;
	scanf ("%d", &n) ;
	for (int i=0; i<n; i++)
	{
		int b ;
		scanf ("%d", &b) ;
		
		map<int, pair<int, int> >::iterator it = mp.find (b) ;
		if (it != mp.end())
			mark[it->second.first][it->second.second] = true ;
	}
	
	bool flag = false ;
	for (int i=0; i<3; i++)
	{
		int sum = 0 ;
		for (int j=0; j<3; j++)
			if (mark[i][j])
				sum++ ;
		
		if (sum == 3)
		{
			flag = true ;
			break ;
		}
	}
	
	for (int j=0; j<3; j++)
	{
		int sum = 0 ;
		for (int i=0; i<3; i++)
			if (mark[i][j])
				sum++ ;
		
		if (sum == 3)
		{
			flag = true ;
			break ;
		}
	}
	
	if (mark[0][0] == true && mark[1][1] == true && mark[2][2] == true)
		flag = true ;
		
	if (mark[0][2] == true && mark[1][1] == true && mark[2][0] == true)
		flag = true ;
		
	if (flag)
		cout << "Yes" << endl ;
	else
		cout << "No" << endl ;
	

	return 0 ;
}