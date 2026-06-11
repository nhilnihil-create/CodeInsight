#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,l;cin>>n>>l;
  vector<int>vec(n);
  int cnt=0;
  rep(i,n){
    vec[i]=l+i;
    cnt+=vec[i];
  }
  int ans1=1e9,ans2=1e9;
  rep(i,n){
    if(abs(vec[i])<ans1){
      ans1=abs(vec[i]);
      ans2=vec[i];
  }
  }
  cout<<cnt-ans2<<endl;
}
      