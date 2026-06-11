#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(n),vec(n);
  rep(i,n){
    cin>>a[i];
    vec[i]=i+1;
  }
  bool ok=false;
  int x=0;
  rep(i,n){
    if(a[i]==vec[x]){
      ok=true;
      x++;
    }
  }
  if(ok)cout<<n-x<<endl;
  else cout<<-1<<endl;
}