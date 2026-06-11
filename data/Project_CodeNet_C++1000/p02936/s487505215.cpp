#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int N;
vector<int> G[200005];
vector<int> color;
vector<int> ans;
void dfs(int now){
  color[now]=1;
  for(int next:G[now]){
    if(color[next]==0){ans[next]+=ans[now];dfs(next);}
  }
  color[now]=2;
}
int main() {
  cin>>N;
  int Q;
  cin>>Q;
  color.resize(N);
  ans.resize(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=0;i<Q;i++){
    int p,x;
    cin>>p>>x;
    p--;
    ans[p]+=x;
  }
  dfs(0);
  for(int i=0;i<N;i++){
    cout<<ans[i]<<endl;
  }
  return 0;  
}