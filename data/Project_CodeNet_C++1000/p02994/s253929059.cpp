#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,l;cin>>n>>l;
  vector<int> vec(n);
  int ans=0,x=1e9;
  rep(i,n){
    vec[i]=i+l;
    ans+=vec[i];
    x=min(x,abs(vec[i]));
  }
  if(ans>0)cout<<ans-x<<endl;
  else cout<<ans+x<<endl;
}