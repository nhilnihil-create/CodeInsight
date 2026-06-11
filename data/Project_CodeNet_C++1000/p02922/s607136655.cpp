#include <iostream>
using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;

  int n = 0;
  int plugs = 1;
  while(true)
  {
    if(plugs >= B)
    {
      cout << n << endl;
      break;
    }
    plugs += A - 1;
    n++;
  }
}