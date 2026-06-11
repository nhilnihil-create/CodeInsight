#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int a , result;
  
  cin >> a;
  
  result = a + pow(a,2) + pow(a,3);
  
  cout << result;
  
  return 0;
}