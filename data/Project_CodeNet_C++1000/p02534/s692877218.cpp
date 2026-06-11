#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<ll, ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
//#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<int> >
#define vll vector<int>
#define mint map<int,int>
#define sz(x) (int)x.size()
#define sll set<int>
#define pll pair<int,int>
#define F first
#define S second
#define INF 1e18
#define inf 1e10
#define NINF -1e16

#define N 1000005
int spf[N];
vll primes,prev[N],next[N];
set<int>s;
void sieve()
{
	rep(i,2,N)
	{
		if (spf[i]==0)
		{
			spf[i]=i;
			for(int j=2*i;j<=N;j+=i)
			{
				if(spf[j]==0)
					spf[j]=i;
			}
		}
	}
}
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    for (int p=2; p<=n; p++) 
    {
        if (prime[p]) 
        {
            primes.pb(p); 
            s.insert(p);
        }
    }    
} 
// bool isPrime(ll n) 
// { 
//     if (n <= 1) 
//         return false; 
//     if (n <= 3) 
//         return true; 
//     if (n % 2 == 0 || n % 3 == 0) 
//         return false; 
//     for (int i = 5; i * i <= n; i = i + 6) 
//         if (n % i == 0 || n % (i + 2) == 0) 
//             return false; 
//     return true; 
// } 
// ll power(ll x,ll y)
// {
//     ll X=x;
//     //X=X%p;//if x is greater than p
//     if(X==0)
//     {
//         return 0;
//     }
//     ll res=1ll;
//     while(y>0)
//     {
//         if(y&1)
//         {
//             res=((res)*(X));
//             y--;
//         }
//         y=y>>1;
//         X=((X)*(X));
//     }
//     // res=(res>=0)?(res%p):(res+p)%p;
//     return(res);
// }
// void dfs(int u, int par){
//     cnt[u] = 1;
//     p[u] = par;
//     for(int i : g[u]){
//         if(i != par){
//             dfs(i,u);
//             cnt[u] += cnt[i];
//         }
//     }
// }
// int children(vll v[],int parent,int src,vll& chil)
// {
// 	int ans =0;
// 	for(auto it:v[src])
// 	{
// 		if(it!=parent)
// 		{
// 			ans+= 1+children(v,src,it,chil);
// 		}
// 	}
// 	chil[src] = ans;
// 	return ans;
 
// }
bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    if (a.F==b.F)
    return a.S<b.S;
    else
    return a.F>b.F;
}
// char a[502][502];
// string s[502];
// int visited[502][502] = {0};
// int n,m,k;
// int x = 0,c=0;
// bool issafe(int i ,int j)
// {
//     if(i>=0&&i<n&&j>=0&&j<m)
//     {
//         if(s[i][j]=='.') return true;
//         else return false;
//     }
//     else return false;
// }
 
// void dfs(int i,int j)
// {
//     if(x==c-k) return;
//     x++;
//     //cout << x << endl;
//     visited[i][j] = 1;
//     //cout << i << " " << j << " "<<visited[i][j]<<endl;
//     if(issafe(i-1,j)&&!visited[i-1][j]) dfs(i-1,j);
//     if(issafe(i+1,j)&&!visited[i+1][j]) dfs(i+1,j);
//     if(issafe(i,j-1)&&!visited[i][j-1]) dfs(i,j-1);
//     if(issafe(i,j+1)&&!visited[i][j+1]) dfs(i,j+1);
//     return;
// }
// int knapSack(int W, int wt[], int val[], int n) 
// {
//     if (n == 0 || W == 0) 
//         return 0;
//     if (wt[n] > W) 
//         return knapSack(W, wt, val, n - 1); 
//     else
//         return max( val[n] + knapSack(W - wt[n], wt, val, n - 1), knapSack(W, wt, val, n - 1)); 
// } 
// void min_self(ll &a,ll b)
// {
//     a=min(a,b);
// }
// void max_self(ll &a,ll b)
// {
//     a=max(a,b);
// }
void dfs(int u,vector<int>g[],bool vis[],int &c)
{
    if (!vis[u])
    {
        vis[u]=1;
        c++;
    }
    for(auto i:g[u])
    {
        if (!vis[i])
        dfs(i,g,vis,c);
    }
}
signed main() {
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand (static_cast <unsigned> (time(0)));
	SieveOfEratosthenes(1000005); 
    //sieve();
	int t=1;
	//cin >> t;
	while (t--) 
	{
	    int n;
	    cin >> n;
	    string s="ACL",res="";
	    rep(i,0,n)
	    res+=s;
	    cout <<res<<endl;
	    
	}
	return 0;
}