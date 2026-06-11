#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL<<60;

int main() {
  int64_t N,M,X,ans=INF;
  cin>>N>>M>>X;
  vector<int64_t> C(N);
  vector<vector<int64_t>> A(N,vector<int64_t>(M));
  rep(i,N){
    cin>>C.at(i);
    rep(j,M){
      cin>>A.at(i).at(j);
    }
  }
  for(int i=0;i<(1<<12);i++){
    bitset<12> s(i);
    bool finish=true;
    int64_t total=0;
    vector<int64_t> score(M,0);
    rep(j,N){
      if(s.test(j)){
        rep(k,M){
          score.at(k)+=A.at(j).at(k);
        }
        total+=C.at(j);
      }
    }
    rep(j,M){
      if(score.at(j)<X) finish=false;
    }
    if(finish) ans=min(ans,total);
  }
  if(ans==INF) cout<<-1;
  else cout<<ans; 
}