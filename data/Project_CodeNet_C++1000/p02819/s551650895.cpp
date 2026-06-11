#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int x;cin>>x;
  while(1){
    //素数判定はO(logN)
    bool ans=true;
    for(int i=2;i<=sqrt(x);i++){
      //xが素数か判定　この場合の計算量は√N
      if(x%i==0)ans=false;
      }
    if(ans)break;
    x++;
  }
  cout<<x<<endl;
}