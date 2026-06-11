#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int H,W;
  cin >> H >> W;
  if(H == 1 || W == 1){
    cout << 1;
  }
  else if (H * W % 2 == 0){
    cout << H * W / 2;
  }
  else {
    cout << (H * W + 1) / 2;
  }
}
  