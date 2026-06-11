#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N,M;
  cin >> N >> M;
  vi u(M),u2(M);
  vvi v(N*3);
  rep(i,M) {
    cin >> u[i] >> u2[i];
    u[i]--;u2[i]--;
    v[u[i]*3].push_back(u2[i]*3+1);
    v[u[i]*3+1].push_back(u2[i]*3+2);
    v[u[i]*3+2].push_back(u2[i]*3);
  }
  int S,T;
  cin >> S >> T;
  S--;T--;
  
  vi dis(N*3,INF);
  dis[S*3]=0;
  queue<int> que;
  que.push(S*3);
  while(!que.empty()) {
    int q=que.front();
    que.pop();
    for(int x:v[q]) {
      if(dis[x]==INF) que.push(x);
      dis[x]=min(dis[x],dis[q]+1);
    }
  }
  
  if(dis[T*3]!=INF) cout << dis[T*3]/3 << endl;
  else cout << -1 << endl;
}