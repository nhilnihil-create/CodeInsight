#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int x;
  x = a;
  a = b;
  b = x;
  x = a;
  a = c;
  c = x;
  cout << a << " " << b << " " << c << " " << endl;

}
