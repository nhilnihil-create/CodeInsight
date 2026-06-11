#include<bits/stdc++.h>
using namespace std;
int main () {
  int X;
  cin >> X;
  int a = X / 100;
  int b = X % 100;
  int kj = (b - 1) / 5;
  kj ++;
  cout << (a >= kj ? 1 : 0) << endl;
}