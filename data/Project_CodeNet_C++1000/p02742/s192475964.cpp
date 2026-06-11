#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int H, W;
  cin >> H >> W;
  
  if (H == 1 || W == 1){
    cout << "1" << endl;
    exit(0);
  }
  
  long long int ans = H * W / 2;
  if (H % 2 == 1 && W % 2 == 1){
    ans++;
  }
  
  cout << ans << endl;
}