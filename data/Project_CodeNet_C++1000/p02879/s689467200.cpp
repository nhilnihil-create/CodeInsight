#include <iostream>
using namespace std;

int main()
{
  int num1, num2;

  cin >> num1 >> num2;

  if(num1 > 9 || num2 > 9)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << num1 * num2 << endl;
  }
}
