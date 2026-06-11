#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N,M,Q,ans=0; cin>>N>>M>>Q;
  vector<int64_t> A(Q),B(Q),C(Q),D(Q);
  rep(i,Q){
    cin>>A.at(i)>>B.at(i)>>C.at(i)>>D.at(i);
    A.at(i)--;
    B.at(i)--;
  }
  bool finish=false;
  vector<int64_t> S(N,1);
  while(true){
    int64_t k=N-1,s=0;
    rep(i,Q){
      if(S.at(B.at(i))-S.at(A.at(i))==C.at(i)) s+=D.at(i);
    }
    ans=max(ans,s);
    while(S.at(k)==M){
      k--;
      if(k==-1){
        finish=true;
        break;
      }
    }
    if(finish) break;
    else{
      S.at(k)++;
      for(int64_t p=k+1; p<N; p++) S.at(p)=S.at(k);
    }
    s=0;
    rep(i,Q){
      if(S.at(B.at(i))-S.at(A.at(i))==C.at(i)) s+=D.at(i);
    }
    ans=max(ans,s);
  }
  cout<<ans;
}
