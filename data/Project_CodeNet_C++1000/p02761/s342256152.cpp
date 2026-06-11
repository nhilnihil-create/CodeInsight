#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;
void YN(bool x){
  if(x) cout<<"Yes";
  else cout<<"No";
}
int main() {
  bool finish=true;
  int N,M; cin>>N>>M;
  vector<int> S(N,-1);
  rep(i,M){
    int a,b; cin>>a>>b;
    a--;
    if(S[a]==-1) S[a]=b;
    else if(S[a]!=b) finish=false;
  }
  if(N!=1 &&S[0]==0) finish=false;
  if(!finish) cout<<-1;
  else{
    if(N==1 &&S[0]==-1) S[0]=0;
    else if(S[0]==-1) S[0]=1;
    rep(i,N){
      if(S[i]==-1) cout<<0;
      else cout<<S[i];
    }
  }   
}
