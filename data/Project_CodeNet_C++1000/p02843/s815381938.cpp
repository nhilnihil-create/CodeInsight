#include <bits/stdc++.h>
using namespace std;
int main() {
  int X;
  cin >> X;
  if(X/100 >= (X%100 + 4) / 5)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}