#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> b(n-1);
  rep(i,n-1)cin>>b[i];
  int cnt=b[0];
  rep(i,n-2){
    if(b[i]<b[i+1])cnt+=b[i];
    else cnt+=b[i+1];
  }
  cnt+=b[n-2];
  cout<<cnt<<endl;
}