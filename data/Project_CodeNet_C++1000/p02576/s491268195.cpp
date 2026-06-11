#include <iostream>
using namespace std;

int main(){
  int a;
  int b;
  int c;
  int d;
  cin >> a >> b >> c;
  if (a%b!=0) d = a/b+1;
  else d = a/b;
  cout << d*c;
}