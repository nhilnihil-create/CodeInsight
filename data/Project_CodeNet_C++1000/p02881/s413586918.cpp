/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "



int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		ll n;
		scanf("%lld",&n);
		ll ans = INTMAX_MAX;
		for (int i=1 ; i<=sqrt(n) ; i++)
		{
			if (n%i==0)
			ans = min(ans,i+(n/i));
		}
		printf("%lld",ans-2);
		
		return 0;
}  
