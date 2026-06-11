#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int x;cin>>x;
  for(int i=1;i<=x/100;i++){
    if(100*i<=x&&x<=105*i){
      cout<<1<<endl;
      return 0;
    }
  }
  cout<<0<<endl;
}