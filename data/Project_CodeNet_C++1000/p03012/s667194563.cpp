#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000000;
//------------------------------------------//

int main(){
  int N;cin>>N;
  int W[100];
  int sum=0;
  int sum_a=0;
  int ans=10000000;
  rep(i,N){
    cin>>W[i];
    sum+=W[i];
  }
  
  rep(T,N){
    rep(i,T+1){
      sum_a+=W[i];
    }
    ans=min(ans,abs(sum-2*sum_a));
    sum_a=0;
  }
  cout<<ans<<endl;
}
      