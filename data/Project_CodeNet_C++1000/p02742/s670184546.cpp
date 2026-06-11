#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll H,W;
  cin >> H >> W;
  ll ans=0;
  if(H==1 || W==1){
    cout << 1 << endl;
    return 0;
  }
  if(H%2==0){
    ans=H*W/2;
  }
  else{
    ans=(H-1)*W/2+(W+1)/2;
  }
  cout << ans << endl;
}