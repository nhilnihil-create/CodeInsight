#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,k;cin>>n>>k;
  vector<int>h(n);
  rep(i,n)cin>>h[i];
  sort(all(h));
  ll cnt=0;
  rep(i,n-k){
    cnt+=h[i];
  }
  cout<<cnt<<endl;
}