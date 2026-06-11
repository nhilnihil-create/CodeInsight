#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

  const ll N = 1000000007;
int main() {
  ll n,k,ans=0;
  cin>>n>>k;
  vector<ll> ruiseki(200001);
  ruiseki[0]=0;
  rep(i,200001){
    ruiseki[i+1]=ruiseki[i]+i+1;
  }
  for(int i=k; i<=n+1; i++){
    ll max_ans,min_ans;
    max_ans=ruiseki[n+1]-ruiseki[n-i+1];
    min_ans=ruiseki[i]-ruiseki[0];
    ans+=max_ans-min_ans+1;
  }
  ans%=N;
  cout<<ans<<endl;
}