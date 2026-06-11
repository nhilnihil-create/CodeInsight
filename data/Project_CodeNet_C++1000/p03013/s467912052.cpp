#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  int N,M;
  cin>>N>>M;
  vector<bool> broken(N+1,false);
  rep(i,M){
    int a; cin>>a;
    broken.at(a)=true;
  }
  vector<int64_t> ans(N+1,0);
  ans.at(0)=1;
  if(!(broken.at(1)))ans.at(1)=1;
  for(int i=2;i<N+1;i++){
    if(!(broken.at(i))){
      ans.at(i)=(ans.at(i-1)+ans.at(i-2))%MOD;
    }
  }
  cout<<ans.at(N);
}
