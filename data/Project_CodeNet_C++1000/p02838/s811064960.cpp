/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define si(x)     scanf("%d", &x)
#define sll(x)    scanf("%lld", &x)
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100000
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define vll(a)	  vector<ll>a
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		ll n;
		sll(n);
		vll(a);
		for (int i=0 ; i<n ; i++)
		{
			ll x;
			sll(x);
			a.pb(x);
		}
		ll res = 0;
		ll fact= 1;
		for (int d=0 ; d<60 ; d++)
		{
			ll even=0,odd=0;
			for (int i=0 ; i<n ; i++)
			{
				 if (a[i] & (1LL << d))
				 odd++;
				 else
				 even++;
			}
		    ll add = (odd * even) % MOD * fact % MOD;
			res = (res + add) % MOD;
			fact = (fact * 2) % MOD;
		}
		cout << res << endl;
		return 0;
}
