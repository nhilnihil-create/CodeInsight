#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int>h(n);
  rep(i,n)cin>>h[i];
  int ans=0,cnt=0;
  reverse(all(h));
  rep(i,n){
    if(h[i]>h[i+1])cnt=0;
    else cnt++;
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}