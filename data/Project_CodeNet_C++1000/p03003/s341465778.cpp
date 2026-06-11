#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define frw(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define in insert
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define vpii vector<pii>
#define vpiii vector<piii>
#define vpll vector<pll>
#define vplll vector<plll>
#define mo 1000000007
inline ll madd(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a+b>=mo)return(a+b)%mo;return(a+b);}
inline ll msub(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;return(((a-b)%mo+mo)%mo);}


vector<ll>v[100005];


int main() {
	ll n,m;
	cin>>n>>m;
	ll s[n],t[m];
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<m;i++)
		cin>>t[i];
	//cin>>s>>t;
	ll k,l;
	k=n;
	l=m;
	ll dp[k+1][l+1];
	for(int i=0;i<=k;i++)
		for(int j=0;j<=l;j++)
			dp[i][j]=0;


	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=l;j++)
		{
			if(i==0||j==0)
				dp[i][j]=1;
			else{
			if(s[i-1]==t[j-1])
				dp[i][j]=madd(dp[i][j],madd(dp[i-1][j],dp[i][j-1]));
			else
				dp[i][j]=msub(madd(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
		}
	}
	}
	cout<<dp[k][l];

}
