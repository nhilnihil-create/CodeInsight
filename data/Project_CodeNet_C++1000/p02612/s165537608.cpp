#include <iostream>
using namespace std;

int main() {
  int b;
  cin >>b;
  int a = b / 1000;
  int c = b - a * 1000;
  if (c != 0)
    {
    c = 1000 - c;
    }
  cout<<c;
	return 0;
}
