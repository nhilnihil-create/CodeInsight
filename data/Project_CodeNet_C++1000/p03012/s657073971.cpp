
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int N,S1=0,S2=0,S3=0,ans=10000;cin>>N;
  vector<int> W(N);
  rep(i,N) cin>>W[i];
  rep(i,N) S3 += W[i];
  for(int T=1;T<N;T++){
    rep(i,T) S1 += W[i];
    S2 = S3-S1;
    if(ans>abs(S1-S2)) ans=abs(S1-S2);
    S1=0;
  }
  cout << ans << endl;
}