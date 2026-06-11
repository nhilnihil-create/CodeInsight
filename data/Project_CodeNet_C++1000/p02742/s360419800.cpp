#include<bits/stdc++.h>
using namespace std;
int main(){
  long long H,W;
  cin >> H >> W;
  long long ans = 0;
  long long sq = H*W;
  if (W == 1 || H ==1){
    ans = 1;
  }
  else{
  if(sq%2LL ==0){
    ans = H*W/2;
  }
  else{
    ans = (H*W/2)+1;
  }
}
cout << ans << endl;
}