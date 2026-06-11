#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int main(){
  int N,M; cin>>N>>M;
  if(N%2){
    rep(i,M){
      cout<<i+1<<" "<<N-i<<endl;
    }
  }else{
    rep(i,M/2+M%2){
      cout<<i+1<<" "<<N-i<<endl;
    }
    for(int i=M/2+M%2;i<M;i++){
      cout<<i+1<<" "<<N-i-1<<endl;
    }
  }
  return 0;
}