#include <iostream>
using namespace std;

int main() {
	int n;
  cin >>n;
  int a;
  a = n / 2;
  if (n - a * 2 != 0)
  {
    a = a+1;
  }
  cout<<a;
	return 0;
}
