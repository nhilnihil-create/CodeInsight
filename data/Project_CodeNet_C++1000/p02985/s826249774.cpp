#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll mod=1000000007;
int main(){
  int i,n,k;
  cin >> n >> k;
  vector<vector<int> > g(100010);
  vector<int> ans(100010,mod);
  for(i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    g[a].push_back(b),g[b].push_back(a);
  }
  stack<P> s;
  s.push(P(0,k));
  ans[0]=k;
  while(!s.empty()){
    P p=s.top();
    s.pop();
    int v=p.first,w;
    if(v==0){
      w=k;
    }
    else{
      w=k-1;
    }
    for(i=0;i<g[v].size();i++){
      int us=g[v][i];
      if(ans[us]!=mod){
        continue;
      }
      w--;
      ans[us]=w;
      s.push(P(us,w));
    }
  }
  ll ans1=1;
  for(i=0;i<n;i++){
    ans1=ans1*ans[i]%mod;
    if(ans[i]<=0){
      cout << 0 << endl;
      return 0;
    }
  }
  ans1%=mod;
  cout << ans1 << endl;
}