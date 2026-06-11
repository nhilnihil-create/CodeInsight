// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int a = 0;
  int b = 0;
  for (int i = 0; i < 4; i++) {
      int s;
      cin >> s;
      a += s;
  }
  
  for (int i = 0; i < 4; i++) {
      int s;
      cin >> s;
      b+= s;
  }
  
  if (a > b) {
      cout << a << endl;
  }else {
      cout << b << endl;
  }
}