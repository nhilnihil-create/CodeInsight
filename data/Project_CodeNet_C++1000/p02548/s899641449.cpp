#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 1000000007
#define inf 1e18
#define PI 3.14159265358979323846264338327950L
#define w(x) int x; cin>>x; while(x--)
using namespace std;
bool sieve[2000006];
void sieve_make() 
{
	memset(sieve,true,sizeof(sieve));
	sieve[0]=sieve[1]=false;
	for(int i=2;i*i<2000006;i++)
	{
		if(sieve[i])
		{
			for(int j=i*i;j<2000006;j+=i)
				sieve[j]=false;
		}
	}
}

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int modexp(int a,int b,int c)
{
	if(a==0) return 0;
	if(b==0) return 1;

	int ans;
	if(b%2==0)
	{
		int small=modexp(a,b/2,c);
		ans=(small*small)%c;
	}
	else
	{
		int small=modexp(a,b-1,c);
		ans=(a%c);
		ans=(small*ans)%c;
	}
	return (ans+c)%c;
}
bool sign(int x)
{
	if(x>0)
		return true;
	return false;
}
int kadane(int* a,int n)
{
	int loc=a[0],glo=a[0];
	for(int i=1;i<n;i++)
	{
		loc=max(a[i],loc+a[i]);
		glo=max(glo,loc);
	}
	return glo;
}

int dp[100005];
int dfs(vector<int>* adj,int sv,bool col,bool* vis,int n)
{
	if(sv==n-1)
		return 1;
	
	int ans=0;
	for(auto i:adj[sv])
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(col)
				ans+=dfs(adj,i,!col,vis,n);
			else
				ans+=dfs(adj,i,!col,vis,n)+dfs(adj,i,col,vis,n);
			vis[i]=0;
		}
	}
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
	
	
	
	
	int n;
	cin>>n;
	
	int ans=0;
	for(int i=1;i<n;i++)
	{
		ans+=(n-1)/i;
	}
	cout<<ans<<endl;
	
}

