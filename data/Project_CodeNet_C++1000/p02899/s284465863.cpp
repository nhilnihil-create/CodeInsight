#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  vector<int> ans(n);
  rep(i,n)ans[a[i]-1]=i+1;
  rep(i,n)cout<<ans[i]<<" ";
  cout<<endl;
}