#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int N,ans=0; cin>>N;
  vector<int> S(N);
  vector<vector<pair<int,int>>> A(N);
  rep(i,N){
    cin>>S[i];
    rep(j,S[i]){
      int x,y; cin>>x>>y;
      A[i].push_back(make_pair(x-1,y));
    }
  }  
  for(int64_t temp=0;temp<(1<<15);temp++){
    int c=0;
    bool K=true;
    bitset<15> s(temp);
    rep(i,N){
      if(s.test(i)){
        rep(j,S[i]){
          if((A[i][j].second==1 && s.test(A[i][j].first)) ||( A[i][j].second==0 && !s.test(A[i][j].first)));
          else K=false;
        }
        c++;
      }
    }
    if(K)ans=max(ans,c);
  }
   cout<<ans<<endl;                                            
}
