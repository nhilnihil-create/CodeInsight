#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
/*

*/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  
  ll N,ans=1; cin>>N;
  string S; cin>>S;
  for(ll i=0; i<N-1; i++){
    if (S[i] == S[i+1])
      continue;
    ans++;
  }
  cout<<ans<<endl;
}