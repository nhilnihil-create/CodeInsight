#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 3e5 + 5 ;
int n ;
int num[maxn] ;
int sum[maxn] ;
bool judge(int k , int x)
{
	int now = upper_bound(num + 1 , num + n + 1 , x) - num ;
	ll s = sum[now - 1] + 1ll * (n - now + 1) * x ;
	if(s >= 1ll * k * x)
	  return 1 ;
	else
	  return 0 ;
}
int main()
{
	scanf("%d" , &n) ;
	memset(num , 0 , sizeof(num)) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		int x ;
		scanf("%d" , &x) ;
		num[x] ++ ;
	}
	sort(num + 1 , num + n + 1) ;
	sum[0] = 0 ;
	for(int i = 1 ; i <= n ; i ++)
	  sum[i] = sum[i - 1] + num[i] ;
	for(int k = 1 ; k <= n ; k ++)
	{
		int ans = 0 ;
		int l = 0 , r = n / k ;
		int mid ;
		while(l <= r)
		{
			mid = (l + r) / 2 ;
			if(judge(k , mid))
			{
				ans = mid ;
				l = mid + 1 ;
			}
			else
			  r = mid - 1 ;
		}
		printf("%d\n" , ans) ;
	}
}