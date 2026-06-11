#include <bits/stdc++.h>
using namespace std;

int main() {
  uint64_t H,W;
  cin >>H>>W;
  if (H ==1||W==1 ){
    cout << 1 << endl;
  }
  else{
    cout << H*(W/2)+(W%2)*(H-H/2) << endl;
  }
}
