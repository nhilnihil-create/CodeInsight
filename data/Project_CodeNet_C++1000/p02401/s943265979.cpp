#include <iostream>
using namespace std;

int main() {
  int a,c;
  char b;

  cin >> a >> b >> c;
  while( b != '?') {
      switch(b) {
          case '+':
              cout << a+c << endl;
              break;
          case '-':
              cout << a-c << endl;
              break;
          case '*':
              cout << a*c << endl;
              break;
          case '/':
              cout << a/c << endl;
              break;

      }
      cin >> a >> b >> c;
  }
}