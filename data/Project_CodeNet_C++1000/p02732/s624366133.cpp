#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;


int main() {
  int64_t N; cin>>N;
  vector<int64_t> S(N+1,0),A(N);
  rep(i,N){
    cin>>A.at(i);
    S.at(A.at(i))++;
  }
  int64_t total=0;
  rep(i,N+1){
    total+=S.at(i)*(S.at(i)-1)/2;
  }
  rep(i,N) cout<<total-(S.at(A.at(i))-1)<<endl;
}
