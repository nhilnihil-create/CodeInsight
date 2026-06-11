#include <iostream>
using namespace std;

int main()
{
  long X;
  cin >> X;
  
  long happiness = 0;

  happiness += X / 500 * 1000;
  X -= X / 500 * 500;
  
  happiness += X / 5 * 5;
  
  cout << happiness << endl;
}