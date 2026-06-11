#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<int, int> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)1000000000000

int memo[100000][3];
vector<vector<int>>G(100000);
int N,M,S,T;
void solve(int from,int pp){
  queue<P>qu;
  qu.push(P(from,pp));
  while(!qu.empty()){
    auto t=qu.front();
    qu.pop();
    int x=t.first;
    int y=(t.second+1)%3;
    for(auto k:G[x]){
      if(memo[k][y]!=-1){continue;}
      memo[k][y]=memo[t.first][t.second]+1;
      qu.push(P(k,y));
    }
  }
  return;
}
int main() {
  cin>>N>>M;
  rep(i,100000){rep(j,3){memo[i][j]=-1;}}
  rep(i,M){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
  }
  cin>>S>>T;S--;T--;
  memo[S][0]=0;
  solve(S,0);
  if(memo[T][0]!=-1){memo[T][0]/=3;}
  cout<<memo[T][0];
}
