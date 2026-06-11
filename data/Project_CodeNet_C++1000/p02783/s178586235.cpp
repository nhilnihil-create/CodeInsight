#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int H, A;
  cin >> H >> A;
  if (H % A != 0)
  {
    H = H / A + 1;
  }
  else
  {
    H /= A;
  }
  cout << H << endl;
}