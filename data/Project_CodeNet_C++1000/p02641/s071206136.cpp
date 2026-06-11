#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int x,n;cin>>x>>n;
  vector<int> p(n),vec(102);
  rep(i,n){
    cin>>p[i];
    vec[p[i]]++;
  }
  int cnt=1e9,ans=0;
  rep(i,102){
    if(vec[i]==0&&abs(x-i)<cnt){
      cnt=abs(x-i);
      ans=i;
    }
  }
  cout<<ans<<endl;
}