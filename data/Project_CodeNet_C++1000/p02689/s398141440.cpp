#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  vector<int> h(n);
  vector<bool> ans(n,true);
  rep(i,n)cin>>h[i];
  rep(i,m){
    int a,b;cin>>a>>b;
    a--;b--;
    if(h[a]<=h[b])ans[a]=false;
    if(h[b]<=h[a])ans[b]=false;
  }
  int cnt=0;
  rep(i,n){
    if(ans[i]==true)cnt++;
  }
  cout<<cnt<<endl;
}