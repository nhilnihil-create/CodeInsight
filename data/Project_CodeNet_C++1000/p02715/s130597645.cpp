#include <bits/stdc++.h>
#include<math.h>
typedef long long ll;
using namespace std;
vector<vector<int>>comp;
vector<int>onecycle;
vector<int>clength;
vector<int>v9;
vector<int>v8;
int cycle_start;
int cycle_end;
vector<int>vbip1;
vector<int>vbip2;
//#define PI 3.1415926535897
void addedge(int u,int v,vector<int>adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfsforconnectedcomponents(int s,vector<int>adj[],int V,int u[],int &count)
{
    v9.push_back(s);
    u[s]=1;
    int i;
    for(i=0;i<adj[s].size();i++)
    {
        if(u[adj[s][i]]==0)
        {
            count++;
            dfsforconnectedcomponents(adj[s][i],adj,V,u,count);
        }
    }
}
void connectedcomponents(int V,vector<int>adj[],int u[])
{
    int i;
    for(i=1;i<V+1;i++)
    {
        if(u[i]==0)
        {
            int count=1;
            dfsforconnectedcomponents(i,adj,V,u,count);
            comp.push_back(v9);
            v9.clear();
        }
    }
}
bool dfs1foronecycle(int s,int V,int color[],vector<int>adj[],int p[])
{
    color[s]=1;
    int i;
    for(i=0;i<adj[s].size();i++)
    {
        if(color[adj[s][i]]==0)
        {
            p[adj[s][i]]=s;
            if(dfs1foronecycle(adj[s][i],V,color,adj,p))
            {
                return true;
            }
        }
        else if(color[adj[s][i]]==1 && p[s]!=adj[s][i])
        {
            cycle_start=adj[s][i];
            cycle_end=s;
            return true;
        }
    }
    color[s]=2;
    return false;
}
void cyclesusingdfs1(int V,vector<int> adj[],int color[],int p[])
{
    int i;
    for(i=1;i<V+1;i++)
    {
        if(color[i]==0 )
        {
            if(dfs1foronecycle(i,V,color,adj,p))
            {
                int count=1;
                i=cycle_end;
                while(i!=cycle_start)
                {
                    i=p[i];
                    count++;
                }
                clength.push_back(count);
                count=0;
            }
        }
    }
}
bool bfsbipartite(vector<int>adj[],int V)
{
    int u[V+1];
    int i;
    for(i=0;i<V+1;i++)
    {
        u[i]=0;
    }
    int color[V+1];
    for(i=0;i<V+1;i++)
    {
        color[i]=-1;
    }
    int s;
    for(s=1;s<V+1;s++)
    {
        if(color[s]==-1)
        {
            u[s]=1;
            color[s]=1;
        queue<int>q;
        q.push(s);
        while(!q.empty())
        {
            int z=q.front();
            q.pop();
            for(i=0;i<adj[z].size();i++)
            {
                int k=adj[z][i];
                if(color[k]==-1)
                {
                    color[k]=1-color[z];
                    u[k]=1;
                    q.push(k);
                }
            }
        }
        }
    }
    int flag[V+1];
    for(i=0;i<V+1;i++)
    {
        flag[i]=0;
    }
    for(i=1;i<V+1;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(color[i]==color[adj[i][j]])
            {
                return false;
            }
            if(color[adj[i][j]]==1 && flag[adj[i][j]]==0)
            {
                flag[adj[i][j]]=1;
                vbip1.push_back(adj[i][j]);
            }
            if(color[adj[i][j]]==0  && flag[adj[i][j]]==0)
            {
                flag[adj[i][j]]=1;
                vbip2.push_back(adj[i][j]);
            }
        }
    }
    return true;
}
void bfs1(int V,int s,vector<int>adj[],int d[],int anc[],int u[])
{
    int i;
    d[s]=0;
    u[s]=1;
    anc[s]=-1;
 
    v8.push_back(s);
    queue<int>q;
    q.push(s);
    vector<int>v;
    while(!q.empty())
    {
        int z=q.front();
        q.pop();
        for(i=0;i<adj[z].size();i++)
        {
            int k=adj[z][i];
            if(u[adj[z][i]]==0)
            {
                d[k]=d[z]+1;
                anc[k]=z;
                u[k]=1;
                q.push(k);
            }
        }
    }
}
 int gcd(int a, int b)
 {
     if (a == 0)
         return b;
     return gcd(b % a, a);
 }
int binarySearch(vector<ll>arr, int l, int r, ll x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        
        if (arr[mid] == x)
            return mid;
  
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        return binarySearch(arr, mid + 1, r, x);
    }
    return l;
}
string bin(ll x,ll n)
{
    string s="";
    while(x!=0)
    {
        if(x%2==0)
        {
            s.push_back('0');
        }
        else
        {
            s.push_back('1');
        }
        x=x/2;
    }
    int l=s.length();
    int i;
   for(i=0;i<n-l;i++)
    {
        s.push_back('0');
    }
    reverse(s.begin(),s.end());
    return s;
}
 vector<ll> prime1(ll n)
{
    vector<ll>v;
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
  
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
  
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
           v.push_back(p);
    
    return v;
}
int nCrModp(int n, int r, int p)
{
    // Optimization for the cases when r is large
    if (r > n - r)
        r = n - r;
  
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int C[r + 1];
    memset(C, 0, sizeof(C));
  
    C[0] = 1; // Top row of Pascal Triangle
  
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++) {
  
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
  
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}
 
int ispal(string s)
{
    int i;
    int l=s.length();
    int flag=0;
    for(i=0;i<l/2;i++)
    {
        if(s[i]!=s[l-1-i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    return 1;
}
void printDivisors(int n)
{
    // Note that this loop runs till square root
    
}
int power(int x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
  
    x = x % p; // Update x if it is more than or
                // equal to p
   
    if (x == 0) return 0; // In case x is divisible by p;
  
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
  
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
map<int,int> PrimeFactors(int n)
{
    map<int,int>ans;
    int i;
    for(i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            n=n/i;
            ans[i]++;
        }
    }
    if(n>1)
    {
        ans[n]++;
    }
    return ans;
}
vector<ll> sieve(int n=1000000)
{
    vector<ll>a(n+1);
    ll i;
    for(i=1;i<n+1;i++)
    {
        a[i]=i;
    }
    ll j;
    for(i=2;i<=n;i++)
    {
        if(a[i]==i)
        {
            for(j=i*i;j<=n;j+=i)
            {
                if(a[j]==j)
                {
                    a[j]=i;
                }
            }
        }
    }
    return a;
}
map<int,int> primefactors(int n,vector<ll> &v)
{
    map<int,int>ans;
    while(n>1)
    {
        ans[v[n]]++;
        n/=v[n];
    }
    return ans;
}
ll mult(ll a,ll b,ll m)
{
    if(b==0)
    {
        return 0;
    }
    ll p=mult(a,b/2,m);
    if(b%2==0)
    {
        return (2*p)%m;
    }
    else
    {
        return (2*p+a)%m;
    }
}
ll powmd(ll a,ll b,ll m)
{
    if(b==0)
    {
        return 1;
    }
    ll p=powmd(a,b/2,m);
    if(b%2==0)
    {
        return (p*p)%m;
    }
    else
    {
        return (((p*p)%m)*a%m)%m;
    }
}
int main()
{
    ll n,k;
    cin>>n>>k;
    ll dp[k+1];
    ll i;
    ll j;
    ll m=pow(10,9)+7;
    ll g;
    for(i=0;i<k+1;i++)
    {
        dp[i]=0;
    }
    ll ans=0;
    for(g=k;g>=1;g--)
    {
        for(j=2*g;j<=k;j+=g)
        {
            dp[g]=(dp[g]%m-dp[j]%m+m)%m;
        }
        ll z=powmd(k/g,n,m);
        dp[g]+=z;
        ans+=dp[g]*g;
        ans=ans%m;
    }
    
    cout<<ans;
}
