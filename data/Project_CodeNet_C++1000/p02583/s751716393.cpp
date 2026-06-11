#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int N;cin>>N;
  vector<ll> L(N);rep(i,N) cin>>L[i];
  
  int ans = 0;
  for(int i=0;i<N-2;i++){
    for(int j=i+1;j<N-1;j++){
      for(int k=j+1;k<N;k++){
        ll maxL = max({L[i],L[j],L[k]});
        if(maxL < L[i]+L[j]+L[k]-maxL && L[i]!=L[j] && L[i]!=L[k] && L[j]!=L[k]) ans++;
      }
    }
  }
           
  cout << ans << endl;
  
}