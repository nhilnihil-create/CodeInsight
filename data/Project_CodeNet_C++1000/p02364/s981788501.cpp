#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define N 10000
vector<int> par(N);
vector<int> ranks(N);

void init(int n)
{
  int i;
  rep(i,n)
  {
    par[i]=i;
    ranks[i]=0;
  }
}

int find(int x)
{
  if(par[x]==x)return x;
  else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
  x=find(x);
  y=find(y);
  if(x==y)return;
  if(ranks[x]<ranks[y])par[x]=y;
  else
  {
    par[y]=x;
    if(ranks[x]==ranks[y])ranks[x]++;
  }
}

bool same(int x, int y)
{
  return find(x) == find(y);
}

int main()
{
  int v,e;cin>>v>>e;
  vector<int> s(e);
  vector<int> t(e);
  vector<int> w(e);
  int i;
  rep(i,e)cin>>s[i]>>t[i]>>w[i];
  vector<pair<int,int>> w_ind(e);
  rep(i,e)w_ind[i]=make_pair(w[i],i);
  sort(all(w_ind));
  init(v);
  int ans=0;
  rep(i,e)
  {
    int ind=w_ind[i].second;
    if(!same(s[ind],t[ind]))
    {
      unite(s[ind],t[ind]);
      ans+=w_ind[i].first;
    }
  }
  cout<<ans<<endl;
}


