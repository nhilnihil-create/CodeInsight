#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int N,X,Y; cin>>N>>X>>Y;
  vector<int64_t> A(N,0);
  for(int i=1;i<N;i++){
    for(int j=i+1;j<=N;j++){
      auto k=min(j-i,min(abs(i-X)+abs(j-Y)+1,abs(i-Y)+abs(j-X)+1));
      A.at(k)++;
    }
  }
  rep(i,N-1){
    cout<<A.at(i+1)<<endl;
  }
}
