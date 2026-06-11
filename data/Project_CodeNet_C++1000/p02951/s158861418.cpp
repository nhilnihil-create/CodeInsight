#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  if(A-B < C) cout << C-(A-B) << endl;
  else cout << 0 << endl;
  
}