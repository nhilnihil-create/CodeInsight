#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N,K; cin>>N>>K;
  vector<int64_t> A(N),S;
  rep(i,N){
    cin>>A.at(i);
    A.at(i)--;
  }
  
  vector<bool> seen(N,true);
  int64_t k=0,l=0;
  
  while(seen.at(k)){
    seen.at(k)=false;
    S.push_back(k);
    k=A.at(k);
  }
  while(S.at(l)!=k) l++;
  if(K<=l) cout<<S.at(K)+1;
  else{
    K-=l;
  int64_t t=S.size()-l,q=K%t;
  cout<<S.at(q+l)+1;
  }
}
