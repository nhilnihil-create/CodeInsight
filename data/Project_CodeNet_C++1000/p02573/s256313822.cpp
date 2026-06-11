#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define _h cout<<"here"<<endl;
#define fill(a,v) memset(a,v,sizeof(a));
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<n;i+=1)
#define prd(a,n) rep(i,n) cout<<a[i]<<" \n"[i==n-1];// printf("%s\n"," " );
#define ff first
#define ss second
#define pu push_back
const int inf = 1e9+10;
const ll INF = 2e18+10;
const int Mod = 1e9+7;
const int MAXN = 1000010;
const int N=2e5+10;
const int M=210;
const int M1=1e9+7;
const int M2=1e9+9;
const int base=131;
int parent[N],n,m;

int find(int x)
{
  int root=x;
  //identify the root
  while(parent[root]>=0) root=parent[root];
  //path compression
  while(x!=root)
  {
    int old=x;
    x=parent[x];
    parent[old]=root;
  }
  return root;
}
bool merge(int x,int y)
{
  //identify roots
  x=find(x);
  y=find(y);
  if(x==y) return false;
  //parent[x] is the negated size of set containing x.
  if(parent[x]>parent[y]) swap(x,y);
  parent[x]+=parent[y];
  parent[y]=x;
  return true;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  memset(parent,-1,sizeof(parent));
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;
    cin>>u>>v;
    merge(u,v);
  }
  int ans=inf;
  for(int i=1;i<=n;i++)
  {
    if(parent[i]<0)
    {
      ans=min(ans,parent[i]);
    }
  }
  ans=-1*ans;
  cout<<ans<<endl;
  return 0;
}
