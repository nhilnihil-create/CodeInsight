#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 1e8;
typedef long long ll;
ll mod = 1e9+7;
long long fast_exp(long long a, long long b)
{
    if(b == 0)
	   return 1;
    else
    {
	   long long res = 1;
	   res = fast_exp(a,b/2);
	   res = (res*res)%mod;
	   if(b%2 == 1)
		  res = (res*a)%mod;
	   return res;
 
    }
}
const ll N = 1e6;
ll n,m;
//string s,t;
int s[3000],t[3000];
ll dp[3000][3000]={};
bool vis[3000][3000]={};
ll num_common(ll first, ll second)
{
	//cout<<"euler\n";
	
	if(first == -1 || second == -1)
		{
			//cout<<"first : "<<first<<"  second: "<<second<<"  ans : "<<1<<endl;
			return 1;
		}	
	else if(vis[first][second] == 1)
		{
			//cout<<"first : "<<first<<"  second: "<<second<<"  ans : "<<dp[first][second]<<endl;

			return dp[first][second];
		}

	
	else
	{
		ll ways = 0;
		//if(first-1>=0)
			ways = (ways + num_common(first-1,second))%mod;
		//if(second-1>=0)
			ways = (ways + num_common(first,second-1))%mod;
		//if(second-1>=0 && first-1>=0)
			ways = (ways - num_common(first-1,second-1)+mod)%mod;
		if(s[first] == t[second])
		{
			
				ways = (ways + num_common(first-1,second-1))%mod;
			
		}
		dp[first][second] = ways;
		vis[first][second] = 1;
		//cout<<"first : "<<first<<"  second: "<<second<<"  ans : "<<dp[first][second]<<endl;

		return dp[first][second];
	}
}


 int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	cin>>n>>m;
	
	for(ll i = 0; i<n ; i++)
	{	
		cin>>s[i];

	}
	for(ll j = 0; j<m ; j++)
		cin>>t[j];

	vis[0][0] = 1;
	dp[0][0] = 1;
	if(s[0] == t[0])
		dp[0][0]+=1;

	cout<<num_common(n-1,m-1)<<endl;
	return 0;
	
}
