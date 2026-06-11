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

int main(){
  int n,m;cin>>n>>m;
  vector<int> g3[3*n];
  rep(i, m){
    int u,v;cin>>u>>v; u--; v--;
    int from = u;
    int to = v;
 
    g3[from].push_back(n+to);
    g3[n+from].push_back(2*n+to);
    g3[2*n+from].push_back(to);
  }
  int s,t;cin>>s>>t;s--;t--;

  vector<int>d(3*n);
  rep(i, 3*n)d[i]=INF;
  d[s]=0;
  queue<pi>q;
  q.push({0,s});
  while(q.size()){
    auto p = q.front(); q.pop();
    int count = p.first;
    int now = p.second;

    if(d[now] < count)continue;

    for(auto c:g3[now]){
      if(d[c]<=count+1)continue;
      d[c]=count+1;
      q.push({d[c], c});
    }
  }

  if(d[t]==INF)cout<<-1<<endl;
  else cout<<d[t]/3<<endl;

  return 0;
}
