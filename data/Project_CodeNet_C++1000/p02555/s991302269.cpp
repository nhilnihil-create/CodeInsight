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

int main()
{
	ll s;
	cin>>s;
	vector<ll> dp(s+1,0);
	dp[0]=1;
	for(int i=3; i<=s; i++){
		for(int j=i-3; j>=0; j--)
			(dp[i]+=dp[j])%=MOD;
	}
	cout<<dp[s];
	return 0;
}
