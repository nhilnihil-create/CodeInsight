#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  bool pos = true;
  cin >> A >> B;
  if(A > 9 || B > 9)
    pos = false;
  if(pos) cout << A * B << "\n";
  else cout << -1 << "\n";
  return 0;
}
