#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> w(n);
  int cnt=0;
  rep(i,n){
    cin>>w[i];
    cnt+=w[i];
  }
  int l=0,ans=1e9;
  rep(i,n-1){
    l+=w[i];
    int r=cnt-l;
    ans=min(ans,abs(l-r));
  }
  cout<<ans<<endl;
}