#include <bits/stdc++.h>

//#define int long long
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int maxn = 3e3+10;
const int INF = 1e9+10;

int dp[maxn][maxn];
vii v;
int n,t;

int solve(int idx,int cap){
	if(idx==n || cap <= 0)
		return 0;
	if(dp[idx][cap]!=-1)
		return dp[idx][cap];
	return dp[idx][cap] = max(solve(idx+1,cap),solve(idx+1,cap-v[idx].ff)+v[idx].ss);
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	///#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#/endif
	cin>>n>>t;
	v=vii(n);
	for(int i=0;i<n;++i){
		cin>>v[i].ff>>v[i].ss;
	}
	sort(all(v));
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,t)<<endl;
	return 0;
}