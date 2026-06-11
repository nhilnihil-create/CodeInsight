#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,c,k;cin>>a>>b>>c>>k;
  rep(i,k){
    if(a>=b)b*=2;
    else if(b>=c)c*=2;
  }
  if(a<b&&b<c)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}