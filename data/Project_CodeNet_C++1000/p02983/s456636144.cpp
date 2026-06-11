/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200005
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int mod = 2019;

int main()
{
	ll l,r;
	cin >> l >> r;
	int ans = INF;
	for (int i=l ; i<=min(r,l+2040) ; i++)
	{
		for (int j=i+1 ; j<=min(r,l+2040) ; j++)
		{
			ans=min(ans,((i%mod)*(j%mod))%mod);
		}
	}
	cout << ans << endl;
}
