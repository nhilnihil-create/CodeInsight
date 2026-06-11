#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int N,M;cin>>N>>M;
  vector<int> H(N+1);
  for(int i=1;i<=N;i++) cin>>H[i];
  vector<int> around_max(N+1,0);
  
  int a,b;
  for(int i=1;i<=M;i++){
    cin>>a>>b;
    around_max[a]=max(around_max[a],H[b]);
    around_max[b]=max(around_max[b],H[a]);
  }
  
  int ans=0;
  for(int i=1;i<=N;i++){
    if(H[i]>around_max[i]) ans++;
  }
  
  cout << ans << endl;
}
