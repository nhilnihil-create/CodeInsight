
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  if(B==1)cout << 0 << endl;
  else cout << (B-2)/(A-1)+1 << endl;
}