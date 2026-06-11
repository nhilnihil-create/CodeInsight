#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<int> V(N);
  rep(i,N)cin>>V[i];
  sort(V.begin(),V.end());
  double ans=V[0];
  rep(i,N-1){
    ans=(ans+V[i+1])/2;
  }
  cout<<ans<<endl;
  return 0;
}