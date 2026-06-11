#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>


#define P push
#define PB push_back
#define F(i,a,b) for (ll i=a; i<=b; i++)
#define FF(i,a,b) for (ll i=b; i>=a; i--)
using namespace std;
typedef long long int ll;
const int maxN=1e5+100;

vector <int> g[maxN],topol;
int n,m,x,y;
bool mark[maxN];
void dfs(int v)
{
  mark[v]=true;
  if(g[v].size())
    F(i,0,g[v].size()-1)
      {
	if(!mark[g[v][i]])
	  dfs(g[v][i]);
      }
  topol.PB(v);
}
void input()
{
  cin>>n>>m;
  F(i,1,m)
    {
      cin>>x>>y;
      g[x+1].PB(y+1);
    }
}
int main()
{
  //ios::sync_with_stdio(false);
  input();
  F(i,1,n)
    {
      if(!mark[i])
	dfs(i);
    }
  reverse(topol.begin(),topol.end());
  F(i,0,topol.size()-1)
    cout<<topol[i]-1<<endl;
  return 0;
}