#include <bits/stdc++.h>
using namespace std;

int main() {
  int l,r,d;
  cin >> l >> r >> d;
  if(l%d != 0){
    cout << r/d-l/d;
  }
  else
    cout << r/d-l/d+1;
}