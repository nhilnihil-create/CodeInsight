#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll a,b;cin>>a>>b;
  for(int i=1;i<=a;i++){
    if(b*i%a==0){
      cout<<b*i<<endl;
      return 0;
    }
  }
}