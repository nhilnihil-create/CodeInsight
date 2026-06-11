#include<bits/stdc++.h>
using namespace std;

int main(void){
  int P, Q, R, min;
  cin >> P >> Q >> R;
  int ans[3];
  ans[0] = P + Q;
  ans[1] = R + Q;
  ans[2] = P + R;
  min = ans[0];
  for(int i = 0; i < 3; i++){
    if(min > ans[i])
      min = ans[i];
  }
  cout << min << "\n";
  return 0;
}
