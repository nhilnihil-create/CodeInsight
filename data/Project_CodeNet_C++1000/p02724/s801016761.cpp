#include <bits/stdc++.h>
using namespace std;

int main(){
  int x;
  int i;
  int k, f;
  int uresisa;
  cin >> x;
  k = x / 500;
  f = (x - (k * 500)) / 5;
  uresisa = k * 1000 + f * 5;
  cout << uresisa << endl;
}