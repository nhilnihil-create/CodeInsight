#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int k,n;cin>>k>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  a.push_back(a[0]+k);
  //円環の問題は１周＋αを考える
  int cnt=0;
  rep(i,n)cnt=max(cnt,a[i+1]-a[i]);
  cout<<k-cnt<<endl;
}