#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t H, W;
  cin >> H >> W;
  
  if(H == 1 || W == 1){
    cout << 1 << endl;
  }
  else{
  int64_t A =((H+1)/2)*((W+1)/2);
  int64_t B =(H/2)*(W/2);
  cout << A+B << endl;
  }
}
