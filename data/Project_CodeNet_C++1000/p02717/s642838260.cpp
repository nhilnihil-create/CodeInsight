#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  int a = x;
  int b = y;
  int c = z;
  
  a = y;
  b = x;
  a = z;
  c = y;
  
  cout << a << " " << b << " " << c << endl;
}

