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

int num[5] ;

int main()
{
	int n, m ;
	scanf ("%d%d", &n, &m) ;
	
	ms (num, -1) ;
	bool flag = true ;
	for (int i=0; i<m; i++)
	{
		int s, c ;
		scanf ("%d%d", &s, &c) ;
		
		if (num[s] == -1)
			num[s] = c ;
		else if (num[s] != c)
			flag = false ;
			
		if (s == 1 && c == 0 && n > 1)
			flag = false ;
		if (s > n)
			flag = false ;
	}
	
	if (!flag)
	{
		cout << -1 << endl ;
		return 0 ;
	}
	
	int ans = 0 ;
	if (n == 1 && m == 0)
		ans = 0 ;
	else
	{
		for (int i=1; i<=n; i++)
		{
			if (num[i] == -1)
				num[i] = (i == 1) ;
			
			ans += pow (10, n-i) * num[i] ;
		}
	}
	
	
	cout << ans << endl ;

	return 0 ;
}