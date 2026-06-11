#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
const int MOD=1000000007;
vector<int>G[200005];
vector<int>ans;
void dfs(int NOW,int BACK){
  for(int NEXT:G[NOW]){
    if(NEXT==BACK){continue;}
    ans[NEXT]+=ans[NOW];
    dfs(NEXT,NOW);
  }
}
int main() {
  int N,Q;
  cin>>N>>Q;
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ans.resize(N);
  for(int i=0;i<Q;i++){
    int p,x;
    cin>>p>>x;
    p--;
    ans[p]+=x;
  }
  dfs(0,-1);
  
  for(int i=0;i<N;i++){
    cout<<ans[i];
    if(i<N-1){cout<<" ";}
  }
  cout<<endl;
  return 0;
}