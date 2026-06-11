#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  long long H, W, ans = 0;
  cin >> H >> W;
  if((H == 1) || (W == 1)){
    cout << 1 << endl;
    return 0;
  }

  if((H % 2) && (W % 2)){
    cout << (H * W) / 2 + 1 << endl;
  }else{
    cout << H * W / 2 << endl;
  }
}