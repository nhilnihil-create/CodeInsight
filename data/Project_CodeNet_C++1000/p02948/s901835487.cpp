#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()
 
int main(){
  ll N,M,ans=0;
  cin >> N >> M;
  vector<P> A(N);
  rep(i,N){
    cin >> A.at(i).first >> A.at(i).second;
  }
  sort(all(A));
  priority_queue<ll> B;
  ll t=0;
  rep(i,M){
    while(t<N&&A.at(t).first<=i+1){
      B.push(A.at(t).second);
      t++;
    }
    if(!B.empty()){
      ans+=B.top();
      B.pop();
    }
  }
  cout << ans << endl;
}
  