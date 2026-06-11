#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int cnt=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++){
        cnt+=gcd(i,gcd(j,k));
      }
    }
  }
  cout<<cnt<<endl;
}