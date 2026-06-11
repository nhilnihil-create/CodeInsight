#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
#define endl        "\n"
#define repp(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) 	for(int i=a;i<=b;i++)
#define IOS         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=2005;
const int M=1e9 + 7;

pair<int,int> a[N];
int n;
int dp[N][N];

int solve(int idx,int i,int j)
{
	if(idx>n)
		return 0;
	if(dp[idx][i]!=-1)
		return dp[idx][i];
	int ans = a[idx].first*(abs(a[idx].second-i)) + solve(idx+1,i+1,j);
	ans = max(ans, a[idx].first*(abs(a[idx].second-j)) + solve(idx+1,i,j-1));
	return dp[idx][i] = ans;
}

int32_t main()
{
	IOS;
	memset(dp,-1,sizeof(dp));	
	cin >> n;
	rep(i,1,n)
	{
		cin >> a[i].first;
		a[i].second = i;	
	}	
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	cout << solve(1,1,n) << endl;
}
