#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, ans;
  cin >> A >> B;
  ans = A - B * 2;
  if(ans <= 0)
    cout << 0 << "\n";
  else
    cout << ans << "\n";
  return 0;
}
