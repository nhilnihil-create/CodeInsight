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


ll gcd(ll a, ll b)
{
    if (a == 0)
    return b;
    return gcd(b % a, a);
}


ll power(ll a,ll b,ll p)
{

    ll res = 1; // Initialize result
    // Update a if it is more than
    // or equal to mod

    a %= p;

    while(b)
    {
    // If b is odd, multiply a with result
    if (b & 1)
    res = (res * a)%p;

    // Here we assume that doing a*a
    // doesn't cause overflow
    a = (a * a) % p;
    b >>= 1; // b = b / 2

    }

    return res;
}

struct UnionFind{
 
 int num;
 vector<int> rank , parent;
  
  UnionFind()
  { }

  UnionFind(int n) : rank(n,1) , parent(n,0)
  {
       num = n; 

       iota(parent.begin() , parent.end() , 0); 
  }

  int find(int x)
  {
     if(x==parent[x])
     return x;

     parent[x] = find(parent[x]);
     return parent[x];
  }

  bool same(int x , int y){
      return find(x)==find(y);
  }

  void unite(int x , int y){
     
     int x_rep = find(x);
     int y_rep = find(y);

     if(x_rep==y_rep)
     return;

     if(rank[x_rep] < rank[y_rep])
     swap(x_rep,y_rep);

     rank[x_rep]+=rank[y_rep];

     parent[y_rep]=x_rep;

     num--;
  }

  int size(int x )
  {
      return rank[find(x)];
  }

  int count() const{
      return num;
  }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;

    UnionFind uf(n);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        a--;
        b--;

        uf.unite(a,b);
    }

    cout<<uf.count() - 1<<endl;

    return 0;
}