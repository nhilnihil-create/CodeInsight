#include <iostream>
using namespace std;

int main()
{
  int num1, num2, num3, total;
  total = 0;

  cin >> num1 >> num2 >> num3;
  total = num1 + num2 + num3;

  if(total >= 22)
  {
    cout << "bust" << endl;
  }
  else
  {
    cout << "win" << endl;
  }
}
