#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int a=1e9,ans=0;
  rep(i,n){
    int p;cin>>p;
    if(a>p){
      ans++;
      a=p;
    }
  }
  cout<<ans<<endl;
}