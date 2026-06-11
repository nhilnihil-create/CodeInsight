#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<iostream>
#define pb push_back
#define fi first
#define se second
#define sz(x)  x.size()
#define cl(x)  x.clear()
#define all(x)  x.begin() , x.end()
#define r(x)  scanf("%d", &x)
#define rr(x , y)  scanf("%d%d" , &x , &y)
#define rst(s)  scanf("%s" , s)
#define rl(x)  scanf("%lld" , &x)
#define rrl(x , y)  scanf("%lld%lld" , &x , &y)
#define w(x)  printf("%d" , x)
#define ww(x , y)  printf("%d %d" , x , y)
#define wl(x)  printf("%lld" , x)
#define wwl(x , y)  printf("%lld %lld" , x , y)
#define sp()  printf(" ")
#define en()  puts("")
#define rep(i , x , n)  for(int i = x ; i <= n ; i ++)
#define per(i , n , x)  for(int i = n ; i >= x ; i --)
#define mem0(x)  memset(x , 0 , sizeof(x))
#define mem_1(x)  memset(x , -1 , sizeof(x))
#define mem_inf(x)  memset(x , inf , sizeof(x))
#define mem__inf(x)  memset(x , -inf , sizeof(x))
#define p_queue priority_queue
#define debug(x)  cout << '*' << x << '\n'
#define ddebug(x , y)  cout << '*' << x << ' ' << y << '\n'
#define ios std::ios::sync_with_stdio(false) , cin.tie(0)
using namespace std ;
//mt19937  rnd(chrono::high_resolution_clock::now().time_since_epoch().count()) ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair<int , int> pii ;
typedef pair<ll , ll> pll ;
typedef pair<int , ll> pil ;
typedef pair<ll , int> pli ;
const int inf = 0x3f3f3f3f ;
const int maxn = 2e5 + 5 ;
const int maxm = 30 ;
const double eps = 1e-6 ;
int n , p ;
char s[maxn] ;
int num[10005] ;
int main()
{
	ll ans = 0 ;
	rr(n , p) ;
	rst(s + 1) ;
	if(p == 2)
	{
		rep(i , 1 , n)  if((s[i] - '0') % 2 == 0)  ans += i ;
		wl(ans) , en() ;
		return 0 ;
	}
	if(p == 5)
	{
		rep(i , 1 , n)  if((s[i] - '0') % 5 == 0)  ans += i ;
		wl(ans) , en() ;
		return 0 ;
	}
	int now = 0 ;
	int base = 1 ;
	mem0(num) ;
	num[0] ++ ;
	per(i , n , 1)
	{
		now = ((s[i] - '0') * base + now) % p ;
		base = (base * 10) % p ;
		num[now] ++ ;
	}
	rep(i , 0 , p - 1)  ans += ll(num[i]) * (num[i] - 1) / 2 ;
	wl(ans) , en() ;
	return 0 ;
}