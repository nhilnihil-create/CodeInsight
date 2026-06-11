#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi; 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int mod = 1e9+7;
const int maxn =2005; 
const int inf = 0x3f3f3f3f;
ll dp[maxn][maxn];
pair<ll,int> a[maxn];
ll cal(pair<ll,int> a,int pos) {
	return a.fi*abs(a.se-pos);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	rep(i,1,n) {
		cin>>a[i].fi;
		a[i].fi=-a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+1+n);
	rep(i,1,n) {
		a[i].fi=-a[i].fi;
		rep(j,0,i-1) {
			int l=j,r=i-1-j;
			dp[l+1][r]=max(dp[l+1][r],dp[l][r]+cal(a[i],l+1));
			dp[l][r+1]=max(dp[l][r+1],dp[l][r]+cal(a[i],n-r));
		}
	}
	ll ans=0;
	rep(i,0,n) ans=max(ans,dp[i][n-i]);
	cout<<ans<<'\n';
	return 0;
}