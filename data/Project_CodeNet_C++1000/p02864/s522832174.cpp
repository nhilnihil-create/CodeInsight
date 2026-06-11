#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353 
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,x;
ll a[305];
ll dp[305][305];

int main(){
	cin >> n >> x;
	repn(i,n) cin >> a[i];
	rep(i,305)rep(j,305) dp[i][j] = 1e18;
	dp[0][0] = 0;
	repn(i,n+1){
		rep(j,i){
			rep(k,305){
				if(dp[j][k] > 5e17) continue;
				if(k+(i-j-1) > x) continue;
				dp[i][k+(i-j-1)] = min(dp[i][k+(i-j-1)],dp[j][k]+max(0LL,a[j]-a[i]));
			}
		}
	}
	ll ans = 1e18;
	rep(i,x+1) ans = min(ans,dp[n+1][i]);
	cout << ans << endl;
}