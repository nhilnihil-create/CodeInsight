#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pi acos(-1.0)
#define eps 1e-9
#define ll long long
#define ull unsigned long long
#define sf scanf
#define pf printf
#define nl printf("\n")
#define	inf (ll)1e15
#define mod 998244353
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend() 
#define sz(x) (int)(x).size()
#define test_case int ___t;scanf("%d", &___t);for(int cs=1;cs<=___t;cs++)

using namespace __gnu_pbds;
using namespace std;

inline string str_inp(int n){char ch[n+5];sf(" %s",ch);return string(ch);}
inline string line_inp(int n)
{char ch[n+5];fgets(ch,n+5,stdin);string s=string(ch);s.pop_back();return s;}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

const int S=3005;
ll n,sum;
ll dp[S+5][S+5];
ll ara[S+5];

ll Solve(ll i,ll taken)
{
	if(i>n)
	{
		if(taken==sum)return 1LL;
		return 0LL;
	}
	if(dp[i][taken]!=-1)return dp[i][taken];
	ll tot=0;
	tot=2*Solve(i+1,taken);
	if(taken+ara[i]<=sum)tot+=Solve(i+1,taken+ara[i]);
	return dp[i][taken]=tot%mod;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //#endif

	while(~sf("%lld %lld",&n,&sum))
	{
		for(int i=1;i<=n;i++)sf("%lld",&ara[i]);
		memset(dp,-1,sizeof dp);
		pf("%lld\n",Solve(1,0));
	}
    return 0;
}


































