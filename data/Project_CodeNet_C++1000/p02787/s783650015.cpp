#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H,N; cin>>H>>N;
  vector<int> A(N);
  vector<int> B(N);
  rep(i,N) cin>>A.at(i)>>B.at(i);
  vector<int> DP(30000,167167167);
  DP[0]=0;
  for(int i=0;i<20000;i++){
    rep(j,N){
      DP[i+A.at(j)]=min(DP[i+A.at(j)],DP[i]+B.at(j));
    }
  }
  sort(A.begin(),A.end());
  int c=A.at(N-1);
  int ans=167167617;
  for(int i=H;i<=H+c;i++){
    ans=min(ans,DP[i]);
  }
  cout<<ans;
}
