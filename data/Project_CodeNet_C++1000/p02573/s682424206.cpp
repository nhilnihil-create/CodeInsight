#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first
#define s second
using namespace std;


ll gcd(ll a, ll b)   //Function to find gcd of two numbers
{
    if (a == 0)
    return b;
    return gcd(b % a, a);
}

struct UnionFind{
  
   vector<int>parent;

   UnionFind(int n)
   { 
       parent = vector<int>(n,-1);

   }

//Find the parent using path compression
   int Find(int x)
   {
       if(parent[x]<0)
       return x;
       
       return parent[x] = Find(parent[x]);
   }
   
   bool Union(int x , int y)
   {
       int x_rep = Find(x);
       int y_rep = Find(y);

       if(x_rep==y_rep)
       return false;
       
       if(parent[x_rep] > parent[y_rep])
       swap(x_rep,y_rep);

       parent[x_rep]+=parent[y_rep];

       parent[y_rep] = x_rep;

       return true;
   }

   int Size(int x)
   {
       return -parent[Find(x)];
   }

};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;

    //makefriends
    UnionFind UF(n);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        u--;v--;

        UF.Union(u,v);
    }

    //Find the maximum friends-set
    int ans=0;

    for(int i=0;i<n;i++)
    {
        ans = max(ans,UF.Size(i));
    }

    cout<<ans<<endl;

    return 0;
}