#include <bits/stdc++.h>
using namespace std;

int main() {
  long long S;
  cin >> S;//s=ad-bc(0,0,a,b,c,d)
  int a=1000000000;
  int b=1;
  int d=(S+999999999)/1000000000;
  int c=(-S+a*d)/b;
  char e=' ';
  cout << "0 0 "<< a << e << b << e << c << e << d << endl;
}
