#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int
#define ld long double

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10
#define PI acos(-1LL)

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();

int h,n;
const int N=1e3+2,M=1e4+2;
vector<pair<int, int>>a;
int dp[N][M];

int sol(int ind,int remain)
{
	d(ind,remain);
	if(remain<=0)
	{
		return 0;
	}

	if(ind>=n)
	{
		return INT_MAX;
	}

	if(dp[ind][remain]!=-1)
	{
		return dp[ind][remain];
	}

	int take=a[ind].ss+sol(ind,remain-a[ind].ff);
	int notake=sol(ind+1,remain);

	return dp[ind][remain]=min(take,notake);
}

int32_t main()
{
    #ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif 

    fast
    
    int t = 1;
	// cin>>t;
	
	while(t--)
	    solve();
	return 0;  
}

void solve()
{
	int i,j;
	cin>>h>>n;

	a.resize(n);

	for(i=0;i<n;i++)
	{
		cin>>a[i].ff>>a[i].ss;
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			dp[i][j]=-1;
		}
	}

	cout<<sol(0,h);


	
}