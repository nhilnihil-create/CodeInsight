#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int k,n;cin>>k>>n;
  vector<int> a(n+1);
  rep(i,n)cin>>a[i];
  a[n]=k+a[0];
  int cnt=0;
  rep(i,n+1){
    cnt=max(cnt,a[i+1]-a[i]);
  }
  cout<<k-cnt<<endl;
}