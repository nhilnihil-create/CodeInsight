#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N; cin>>N;
  vector<int64_t> S(60);
  rep(i,N){
    int64_t a; cin>>a;
    bitset<60> t(a);
    rep(j,60){
      if(t.test(j)){
        S.at(59-j)++;
      }
    }
  }
  reverse(S.begin(),S.end());
  int64_t ans=0,k=1;
  rep(i,60){
    auto temp=(k*S.at(i))%MOD;
    ans+=temp*(N-S.at(i));
    ans%=MOD;
    k*=2;
    k%=MOD;
  }
  cout<<ans;
}
