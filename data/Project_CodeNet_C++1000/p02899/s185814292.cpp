#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;
const int mxn=100005;
vi adj[mxn];
int s[mxn];
int ans=0;

int dfs(vector<bool> &vis,int start,int init)
{
  // if(s[start]!=init)
  // {
  //   ans++;
  //   swap(s[i],s[start]);
  // }
  vis[start]=true;
  for(int i:adj[start])
  {
    if(!vis[i])
    {
      dfs(vis,i,init^1);
    }
  }
} 

int main()
{
  fastio;
 
  
  int n;
  cin>>n;
  vi a(n+1),b(n+1);
  range(i,1,n+1)
  {
    cin>>a[i];
    b[a[i]]=i;
  }
  range(i,1,n+1)
  {
    cout<<b[i]<<' ';
  }
}
