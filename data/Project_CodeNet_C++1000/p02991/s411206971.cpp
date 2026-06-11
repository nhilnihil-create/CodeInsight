#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 10000000

using namespace std;

#define MAXN 100001

int main(){
  int n,m;cin>>n>>m;
  vector<vector<int>>g(MAXN*3);
  rep(i, m){
    int u,v;cin>>u>>v; u--,v--;
    g[u].push_back(n+v);
    g[n+u].push_back(2*n+v);
    g[2*n+u].push_back(v);
  }
  int s,t;cin>>s>>t;s--,t--;

  vector<int>d(3*n);
  rep(i, 3*n)d[i]=INF;
  d[s]=0;

  queue<pi>q;
  q.push({0, s});
  while(q.size()){
    int now = q.front().second;
    int cost = q.front().first;
    q.pop();
    if(d[now]<cost)continue;

    for(auto c:g[now]){
      if(d[c]<=cost+1)continue;
      d[c]=cost+1;
      q.push({d[c], c});
    }
  }

  if(d[t]==INF)cout<<-1<<endl;
  else cout<<d[t]/3<<endl;

  return 0;
}