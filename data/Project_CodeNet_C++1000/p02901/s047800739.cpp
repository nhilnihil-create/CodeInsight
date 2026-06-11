#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int to[1<<12],from[1<<12];

int main(){
  int N,M; cin>>N>>M;
  int A[M],B[M];
  vector<vector<int>> V(M);
  rep(i,M){
    cin>>A[i]>>B[i];
    rep(j,B[i]){
      int c; cin>>c; c--;
      V[i].push_back(c);
    }
  }
  rep(i,1<<N) from[i]=to[i]=1e9;
  from[0]=0;
  rep(i,M){
    rep(j,(1<<N)){
      to[j]=min(to[j],from[j]);
      int bit=j;
      for(int c:V[i]) bit|=1<<c;
      to[bit]=min(to[bit],from[j]+A[i]);
    }
    swap(to,from);
  }
  if(from[(1<<N)-1]==1e9) cout<<"-1\n";
  else cout<<from[(1<<N)-1]<<endl;
  return 0;
}