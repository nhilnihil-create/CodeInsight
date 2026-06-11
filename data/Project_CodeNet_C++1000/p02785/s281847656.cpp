#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  ll N,K,ans=0;
  cin >> N >> K;
  if(N<=K) ans=0;
  else{
    vector<ll> H(N);
    rep(i,N) {
      cin >> H[i];
    }
    sort(H.begin(),H.end());
    rep(i,N-K) {
      ans+=H[i];
    }
  }
  
  cout << ans << endl;
  return 0; 
}