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
  int ans=1e9;
  rep(i,n){
    ans=min(ans,abs(vec[i]));
  }
  if(cnt>=0)cout<<cnt-ans<<endl;
  else cout<<cnt+ans<<endl;
}