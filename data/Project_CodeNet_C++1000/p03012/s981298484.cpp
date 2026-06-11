#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int>vec(n);
  rep(i,n)cin>>vec[i];
  int ans=1e9;
  for(int i=1;i<n;i++){
    int l=0,r=0;
    for(int j=0;j<i;j++)l+=vec[j];
    for(int j=i;j<n;j++)r+=vec[j];
    ans=min(ans,abs(l-r));
  }
  cout<<ans<<endl;
}