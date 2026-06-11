#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  int temp;
  
  cin >> a >> b >> c;
  
  temp = a;
  a = b;
  b = temp;
  
  temp = a;
  a = c;
  c = temp;
  
  cout << a << ' ' << b << ' ' << c << endl;
}