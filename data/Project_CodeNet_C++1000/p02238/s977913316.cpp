#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   for(int i=0;i<(n);++i)
#define SORT(c)    sort((c).begin(),(c).end())
#define CLR(a)     memset((&a), 0 ,sizeof(a))//clear memory
#define dump(x)    cerr << #x << " = " << (x) << endl;//debug
#define debug(x)   cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define EPS        1e-10//sample:if((double)>=(double)+EPS)
//cin,cout release
//std::cin.tie(0);
//ios::sync_with_stdio(false);

using namespace std;
int n,v[100+1][100+1]={},color[100+1]={},tim,d[1000],f[1000];
void visit(int u){
  color[u]=1;
  d[u]=++tim;
  rep(i,n){
    if(v[u][i]==0)continue;
    if(color[i]==0)
      visit(i);
  }
  color[u]=2;
  f[u]=++tim;
}
void dfs(){
  rep(i,n)color[i]=0;
  tim = 0;
  rep(i,n){
    if(color[i]==0)
      visit(i);
  }
}

int main(){
  cin>>n;
  int u,k,in;
  rep(i,n){
    cin>>u>>k;
    rep(j,k){
      cin>>in;
      v[u-1][in-1]=1;
    }
  }
  dfs();
  rep(i,n)cout<<i+1<<" "<<d[i]<<" "<<f[i]<<endl;
  return 0;
}

