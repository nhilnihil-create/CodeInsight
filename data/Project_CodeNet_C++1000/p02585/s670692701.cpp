#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define int long long
#define fi first
#define se second
#define ncr(n,r) fact[n]*modInv(fact[r])*modInv(fact[n-r])
#define modInv(a) binExp(a,mod-2)
#define mod 1000000007
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define make_graph(k) int x,y; f0(i,0,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define test int t;cin>>t;while(t--)

vector<int> chain;
int vis[5001];
int p[5001];
int c[5001];
int n,k;
int curMax;

void start(int);
void dfs(int);

signed main()
{
    fast

    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif

    cin>>n>>k;

    f1(i,0,n) vis[i] = 0;
    f1(i,1,n)
    {
        cin>>p[i];
    }
    f1(i,1,n)
    {
        cin>>c[i];
    }
    
    curMax = LLONG_MIN;

    f1(i,1,n)
    {
        if(!vis[i])
        {
            start(i);
        }
    }
    cout<<curMax;
}

void start(int v)
{
    chain.clear();
    dfs(v);
    
    f0(i,0,chain.size())
    {
    	int pathLen = 0;
    	int pathSum = 0;
    	curMax = max(curMax, c[chain[i]]);
    	int chainSum = 0;
    	for(auto x : chain) chainSum += c[x];

    	f1(j,1,chain.size())
    	{
    		if(j > k) break;
    		pathSum += c[chain[(i+j)%chain.size()]];
    		int score;
    		if(chainSum > 0)
    		{
    			score = pathSum + (k-j)/chain.size() * chainSum;
    		}
    		else
    		{
    			score = pathSum;
    		}
    		//cout<<"score = "<<score<<'\n';
    		curMax = max(curMax, score);
    		if((i+j)%k == i) break;
    	}
    	//cout<<"------\n";
    }
}

void dfs(int v)
{
    vis[v] = 1;
    chain.pb(v);
    if(vis[p[v]]) return;
    dfs(p[v]);
}