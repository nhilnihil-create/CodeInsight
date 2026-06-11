#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  n %= 1000;
  if (n==0)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << 1000 - n << endl;
  }
  return 0;

}