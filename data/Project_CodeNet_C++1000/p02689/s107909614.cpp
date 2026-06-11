#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  vector<int> h(n),vec(n);
  rep(i,n)cin>>h[i];
  rep(i,m){
    int a,b;cin>>a>>b;
    a--;b--;
    if(h[a]<=h[b])vec[a]++;
    if(h[b]<=h[a])vec[b]++;
  }
  int ans=0;
  rep(i,n){
    if(vec[i]==0)ans++;
  }
  cout<<ans<<endl;
}